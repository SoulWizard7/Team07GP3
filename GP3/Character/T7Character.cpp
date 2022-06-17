#include "T7Character.h"

#include "T7AmmoComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GP3/Gun/T7ShootProjectile.h"
#include "GP3/Library/T7PhysicsBlueprintLibrary.h"
#include "GP3/Puzzle/Interactable/T7PushComponent.h"
#include "GP3/Puzzle/Interactable/T7TraceShootComponent.h"
#include "Kismet/KismetMathLibrary.h"

AT7Character::AT7Character()
{
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	PushComponent = CreateDefaultSubobject<UT7PushComponent>(TEXT("PushComponent"));
	TraceShootComponent = CreateDefaultSubobject<UT7TraceShootComponent>(TEXT("TraceShootComponent"));
	ShootProjectileComponent = CreateDefaultSubobject<UT7ShootProjectile>(TEXT("ShootProjectileComponent"));
	AmmoComponent = CreateDefaultSubobject<UT7AmmoComponent>(TEXT("AmmoComponent"));

	TrajectoryHeight = 50.f;
	AimRange = 10000.f;
}

void AT7Character::BeginPlay()
{
	Super::BeginPlay();
	ShootProjectileComponent->ProjectileType = EProjectileTypes::Levitate;
}

void AT7Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AT7Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AT7Character::AimTracing()
{
	const FVector StartLocation = CameraComponent->GetComponentLocation() + CameraComponent->GetForwardVector() * 10.f;
	const FVector EndLocation = StartLocation + CameraComponent->GetForwardVector() * AimRange;
	
	// Aim trace
	GetWorld()->LineTraceSingleByChannel(
		AimHitResult,
		StartLocation,
		EndLocation,
		AimCollisionChannel);
	
	if (AimHitResult.bBlockingHit)
	{
		AimTargetLocation = AimHitResult.Location;
		bInShootingRange = true;
	}
	else
	{
		AimTargetLocation = EndLocation;
		bInShootingRange = false;
	}
	
	// Calculate trajectory parameters
	TrajectoryRange = FVector::Distance(AimTargetLocation, TrajectoryShootOrigin->GetComponentLocation());
	TrajectoryAngle = UT7PhysicsBlueprintLibrary::GetAngleDegrees(TrajectoryRange, TrajectoryHeight);
	TrajectoryImpulse = UT7PhysicsBlueprintLibrary::GetImpulseFromDegrees(TrajectoryHeight, TrajectoryAngle);

	// Set origin rotation
	const FRotator DirectionRotation = UKismetMathLibrary::FindLookAtRotation(TrajectoryShootOrigin->GetComponentLocation(), AimTargetLocation);
	TrajectoryShootOrigin->SetWorldRotation(FRotator(DirectionRotation.Pitch + TrajectoryAngle, DirectionRotation.Yaw, 0.f));

	// Set up vector from direction
	const FVector Direction = (AimTargetLocation - TrajectoryShootOrigin->GetComponentLocation()).GetSafeNormal();
	TrajectoryUpVector = UKismetMathLibrary::RotateAngleAxis(Direction, 90.f, -TrajectoryShootOrigin->GetRightVector());
	TrajectoryUpVector.Normalize();
}

void AT7Character::SetShootOrigin(USceneComponent* ShootOrigin)
{
	TrajectoryShootOrigin = ShootOrigin;
}

FVector AT7Character::GetAdjustedUpVector()
{
	return UT7PhysicsBlueprintLibrary::GetAdjustedGravity(TrajectoryUpVector.GetSafeNormal());
}

void AT7Character::Shoot()
{
	if (AmmoComponent == nullptr)
	{
		LOG("Couldn't shoot, no ammo component");
		return;
	}
	ShootProjectileComponent->FireProjectile(TrajectoryShootOrigin->GetComponentTransform(), TrajectoryShootOrigin->GetForwardVector(), TrajectoryImpulse, GetAdjustedUpVector());
}

