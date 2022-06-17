#include "T7AmmoComponent.h"

UT7AmmoComponent::UT7AmmoComponent(){}

void UT7AmmoComponent::AddFreezeAmmo()
{
	if(FreezeAmmo < MaxFreezeAmmo)
	{
		FreezeAmmo += 1;
		EffectedFreeze--;
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.0, FColor::Blue, FString::Printf(TEXT("Freeze ammo: %d"), FreezeAmmo));
		OnAddFreezeAmmo.Broadcast();
	}
}
void UT7AmmoComponent::RemoveFreezeAmmo()
{
	if(FreezeAmmo > 0)
	{
		FreezeAmmo -= 1;
		EffectedFreeze++;
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.0, FColor::Blue, FString::Printf(TEXT("Freeze ammo: %d"), FreezeAmmo));
		OnRemoveFreezeAmmo.Broadcast();
	}
}

void UT7AmmoComponent::AddStickyAmmo()
{
	if(StickyAmmo < MaxStickyAmmo)
	{
		StickyAmmo += 1;
		EffectedSticky--;
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.0, FColor::Yellow, FString::Printf(TEXT("Sticky ammo: %d"), StickyAmmo));
		OnAddStickyAmmo.Broadcast();
	}
}

void UT7AmmoComponent::RemoveStickyAmmo()
{
	if(StickyAmmo > 0)
	{
		StickyAmmo -= 1;
		EffectedSticky++;
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.0, FColor::Yellow, FString::Printf(TEXT("Sticky ammo: %d"), StickyAmmo));
		OnRemoveStickyAmmo.Broadcast();
	}
}
void UT7AmmoComponent::AddLevitateAmmo()
{
	if(LevitateAmmo < MaxLevitateAmmo)
	{
		LevitateAmmo += 1;
		EffectedLevitate--;
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.0, FColor::Yellow, FString::Printf(TEXT("Levitate ammo: %d"), LevitateAmmo));
		OnAddLevitateAmmo.Broadcast();
	}
}

void UT7AmmoComponent::RemoveLevitateAmmo()
{
	if(LevitateAmmo > 0)
	{
		LevitateAmmo -= 1;
		EffectedLevitate++;
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.0, FColor::Yellow, FString::Printf(TEXT("Levitate ammo: %d"), LevitateAmmo));
		OnRemoveLevitateAmmo.Broadcast();
	}
}

void UT7AmmoComponent::BeginPlay()
{
	Super::BeginPlay();
	ReplenishAmmo();
}

void UT7AmmoComponent::ReplenishAmmo()
{
	LevitateAmmo = MaxLevitateAmmo;
	StickyAmmo = MaxStickyAmmo;
	FreezeAmmo = MaxFreezeAmmo;
}


