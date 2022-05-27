#include "T7ShootProjectile.h"

#include "T7FreezeProjectile.h"
#include "T7LevitateProjectile.h"
#include "T7ProjectileMovementComponent.h"
#include "T7StickyProjectile.h"

UT7ShootProjectile::UT7ShootProjectile()
{
	
}

void UT7ShootProjectile::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.f, FColor::Yellow, TEXT("Sticky Selected"), true, FVector2D(1.f));
}

void UT7ShootProjectile::FireProjectile(FTransform SpawnTransform, FVector ForwardVector)
{		
	switch (ProjectileType)
	{
	case EProjectileTypes::Frozen:
		
		ShootFreezeProjectile(SpawnTransform, ForwardVector);
		
		break;
	case EProjectileTypes::Levitate:
		
		ShootLevitateProjectile(SpawnTransform, ForwardVector);
		
		break;
	case EProjectileTypes::Sticky:

		ShootStickyProjectile(SpawnTransform, ForwardVector);		
		
		break;
	}
}

void UT7ShootProjectile::SetGunToSticky()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.f, FColor::Yellow, TEXT("Sticky Selected"), true, FVector2D(1.f));
	ProjectileType = EProjectileTypes::Sticky;
}

void UT7ShootProjectile::SetGunToUseFreeze()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.f, FColor::Yellow, TEXT("Freeze Selected"), true, FVector2D(1.f));
	ProjectileType = EProjectileTypes::Frozen;
}

void UT7ShootProjectile::SetGunToUseLevitate()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.f, FColor::Yellow, TEXT("Levitate Selected"), true, FVector2D(1.f));
	ProjectileType = EProjectileTypes::Levitate;
}

void UT7ShootProjectile::ShootLevitateProjectile(FTransform SpawnTransform, FVector ForwardVector)
{
	AT7LevitateProjectile* LevitateProj;
	UT7ProjectileMovementComponent* ProjectileMovementComponent;

	LevitateProj = GetWorld()->SpawnActor<AT7LevitateProjectile>(LevitateProjectile, SpawnTransform);
	ProjectileMovementComponent = LevitateProj->FindComponentByClass<UT7ProjectileMovementComponent>();
	ProjectileMovementComponent->ForwardVector = ForwardVector;

	if(ProjectileMovementComponent == nullptr)
	{
		FString msg1 = FString::Printf(TEXT ("ProjectileMovementComponent == nullptr"));
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.f, FColor::Green, msg1, true, FVector2D(1.f));
	}
	else
	{
		FString msg2 = ProjectileMovementComponent->ForwardVector.ToString();
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.f, FColor::Green, msg2, true, FVector2D(1.f));			
		ProjectileMovementComponent->TriggerImpulse();
	}
}

void UT7ShootProjectile::ShootFreezeProjectile(FTransform SpawnTransform, FVector ForwardVector)
{
	AT7FreezeProjectile* FreezeProj;
	UT7ProjectileMovementComponent* ProjectileMovementComponent;
	
	FreezeProj = GetWorld()->SpawnActor<AT7FreezeProjectile>(FreezeProjectile, SpawnTransform);
	ProjectileMovementComponent = FreezeProj->FindComponentByClass<UT7ProjectileMovementComponent>();
	ProjectileMovementComponent->ForwardVector = ForwardVector;

	if(ProjectileMovementComponent == nullptr)
	{
		FString msg1 = FString::Printf(TEXT ("ProjectileMovementComponent == nullptr"));
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.f, FColor::Green, msg1, true, FVector2D(1.f));
	}
	else
	{
		FString msg2 = ProjectileMovementComponent->ForwardVector.ToString();
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.f, FColor::Green, msg2, true, FVector2D(1.f));			
		ProjectileMovementComponent->TriggerImpulse();
	}
}

void UT7ShootProjectile::ShootStickyProjectile(FTransform SpawnTransform, FVector ForwardVector)
{
	AT7StickyProjectile* StickyProj;
	UT7ProjectileMovementComponent* ProjectileMovementComponent;
	
	StickyProj = GetWorld()->SpawnActor<AT7StickyProjectile>(StickyProjectile, SpawnTransform);
	ProjectileMovementComponent = StickyProj->FindComponentByClass<UT7ProjectileMovementComponent>();
	ProjectileMovementComponent->ForwardVector = ForwardVector;

	if(ProjectileMovementComponent == nullptr)
	{
		FString msg1 = FString::Printf(TEXT ("ProjectileMovementComponent == nullptr"));
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.f, FColor::Green, msg1, true, FVector2D(1.f));
	}
	else
	{
		FString msg2 = ProjectileMovementComponent->ForwardVector.ToString();
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.f, FColor::Green, msg2, true, FVector2D(1.f));			
		ProjectileMovementComponent->TriggerImpulse();
	}
	
}
