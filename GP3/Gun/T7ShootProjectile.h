#pragma once
#include "T7FreezeProjectile.h"
#include "Components/ActorComponent.h"
#include "T7ShootProjectile.generated.h"

class AT7FreezeProjectile;
class AT7LevitateProjectile;
class AT7StickyProjectile;
class UT7AmmoComponent;

UENUM(BlueprintType)
enum class EProjectileTypes : uint8
{
	Levitate,
	Frozen,
	Sticky,
	None
};

UCLASS(Meta = (BlueprintSpawnableComponent))
class UT7ShootProjectile : public UActorComponent
{
	GENERATED_BODY()
public:
	UT7ShootProjectile();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void FireProjectile(FTransform SpawnTransform, FVector ForwardVector, float ImpulseFromDegrees, FVector AdjustedGravity);

	UFUNCTION(BlueprintCallable)
	void SetGunToSticky();

	UFUNCTION(BlueprintCallable)
	void SetGunToUseFreeze();
	
	UFUNCTION(BlueprintCallable)
	void SetGunToUseLevitate();

	UFUNCTION()
	void ShootLevitateProjectile(
		FTransform SpawnTransform,
		FVector ForwardVector,
		float ImpulseFromDegrees,
		FVector AdjustedGravity) const;

	UFUNCTION()
	void ShootFreezeProjectile(
		FTransform SpawnTransform,
		FVector ForwardVector,
		float ImpulseFromDegrees,
		FVector AdjustedGravity) const;

	UFUNCTION()
	void ShootStickyProjectile(
		FTransform SpawnTransform,
		FVector ForwardVector,
		float ImpulseFromDegrees,
		FVector AdjustedGravity) const;

	UFUNCTION(BlueprintCallable)
	void SetAmmoComponent(UT7AmmoComponent* AmmoComp);

public:
	UPROPERTY(BlueprintReadOnly)
	class UT7AmmoComponent* AmmoComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EProjectileTypes ProjectileType = EProjectileTypes::Frozen;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AT7FreezeProjectile> FreezeProjectile;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AT7LevitateProjectile> LevitateProjectile;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AT7StickyProjectile> StickyProjectile;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShootFreeze);
	UPROPERTY(BlueprintAssignable)
	FOnShootFreeze OnShootFreeze;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShootLevitate);
	UPROPERTY(BlueprintAssignable)
	FOnShootLevitate OnShootLevitate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShootSticky);
	UPROPERTY(BlueprintAssignable)
	FOnShootSticky OnShootSticky;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShootNoAmmo);
	UPROPERTY(BlueprintAssignable)
	FOnShootNoAmmo OnShootNoAmmo;
	
	FActorSpawnParameters SpawnParameters;
};