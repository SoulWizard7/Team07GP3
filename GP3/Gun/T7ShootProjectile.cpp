#include "T7ShootProjectile.h"
#include "T7FreezeProjectile.h"
#include "T7LevitateProjectile.h"
#include "T7ProjectileMovementComponent.h"
#include "T7StickyProjectile.h"
#include "T7AmmoComponent.h"
#include "GP3/Library/T7Debug.h"

UT7ShootProjectile::UT7ShootProjectile(){}

void UT7ShootProjectile::BeginPlay()
{
	Super::BeginPlay();
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
}

void UT7ShootProjectile::FireProjectile(FTransform SpawnTransform, FVector ForwardVector, float ImpulseFromDegrees, FVector AdjustedGravity)
{		
	switch (ProjectileType)
	{
	case EProjectileTypes::Frozen:
		ShootFreezeProjectile(SpawnTransform, ForwardVector, ImpulseFromDegrees, AdjustedGravity);
		break;
		
	case EProjectileTypes::Levitate:
		ShootLevitateProjectile(SpawnTransform, ForwardVector, ImpulseFromDegrees, AdjustedGravity);
		break;
		
	case EProjectileTypes::Sticky:
		ShootStickyProjectile(SpawnTransform, ForwardVector, ImpulseFromDegrees, AdjustedGravity);		
		break;
	}
}

void UT7ShootProjectile::SetGunToSticky()
{
	ProjectileType = EProjectileTypes::Sticky;
}

void UT7ShootProjectile::SetGunToUseFreeze()
{
	ProjectileType = EProjectileTypes::Frozen;
}

void UT7ShootProjectile::SetGunToUseLevitate()
{
	ProjectileType = EProjectileTypes::Levitate;
}

void UT7ShootProjectile::ShootLevitateProjectile(FTransform SpawnTransform, FVector ForwardVector, float ImpulseFromDegrees, FVector AdjustedGravity) const
{
	if(AmmoComponent->LevitateAmmo <= 0)
	{
		OnShootNoAmmo.Broadcast();
		return;
	}

	AT7LevitateProjectile* LevitateProj = GetWorld()->SpawnActor<AT7LevitateProjectile>(LevitateProjectile, SpawnTransform, SpawnParameters);
	if (LevitateProj == nullptr)
	{
		return;
	}
	UT7ProjectileMovementComponent* ProjectileMovementComponent = LevitateProj->FindComponentByClass<UT7ProjectileMovementComponent>();
	if (ProjectileMovementComponent == nullptr)
	{
		return;
	}
	ProjectileMovementComponent->PC->AddImpulse(ImpulseFromDegrees * ForwardVector);
	ProjectileMovementComponent->AdjustedGravity = AdjustedGravity;
	OnShootLevitate.Broadcast();
}

void UT7ShootProjectile::ShootFreezeProjectile(FTransform SpawnTransform, FVector ForwardVector, float ImpulseFromDegrees, FVector AdjustedGravity) const
{
	if(AmmoComponent->FreezeAmmo <= 0)
	{
		OnShootNoAmmo.Broadcast();
		return;
	}
	
	AT7FreezeProjectile* FreezeProj = GetWorld()->SpawnActor<AT7FreezeProjectile>(FreezeProjectile, SpawnTransform, SpawnParameters);
	if (FreezeProj == nullptr)
	{
		return;
	}
	UT7ProjectileMovementComponent* ProjectileMovementComponent = FreezeProj->FindComponentByClass<UT7ProjectileMovementComponent>();
	if (ProjectileMovementComponent == nullptr)
	{
		return;
	}
	ProjectileMovementComponent->PC->AddImpulse(ImpulseFromDegrees * ForwardVector);
	ProjectileMovementComponent->AdjustedGravity = AdjustedGravity;
	OnShootFreeze.Broadcast();
}

void UT7ShootProjectile::ShootStickyProjectile(FTransform SpawnTransform, FVector ForwardVector, float ImpulseFromDegrees, FVector AdjustedGravity) const
{
	if(AmmoComponent->StickyAmmo <= 0)
	{
		OnShootNoAmmo.Broadcast();
		return;
	}
	const AT7StickyProjectile* StickyProj = GetWorld()->SpawnActor<AT7StickyProjectile>(StickyProjectile, SpawnTransform, SpawnParameters);
	if (StickyProj == nullptr)
	{
		return;
	}
	UT7ProjectileMovementComponent* ProjectileMovementComponent = StickyProj->FindComponentByClass<UT7ProjectileMovementComponent>();
	if (ProjectileMovementComponent == nullptr)
	{
		return;
	}
	ProjectileMovementComponent->PC->AddImpulse(ImpulseFromDegrees * ForwardVector);
	ProjectileMovementComponent->AdjustedGravity = AdjustedGravity;
	OnShootSticky.Broadcast();
}

void UT7ShootProjectile::SetAmmoComponent(UT7AmmoComponent* AmmoComp)
{
	AmmoComponent = AmmoComp;
}
