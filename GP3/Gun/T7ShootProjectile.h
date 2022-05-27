#pragma once
#include "T7FreezeProjectile.h"
#include "Components/ActorComponent.h"
#include "T7ShootProjectile.generated.h"

class AT7FreezeProjectile;
class AT7LevitateProjectile;
class AT7StickyProjectile;

UENUM()
enum class EProjectileTypes
{
	Frozen,
	Levitate,
	Sticky
};

UCLASS(Meta = (BlueprintSpawnableComponent))
class UT7ShootProjectile : public UActorComponent
{
	GENERATED_BODY()
public:
	UT7ShootProjectile();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void FireProjectile(FTransform SpawnTransform, FVector ForwardVector);

	UPROPERTY(EditAnywhere)
	EProjectileTypes ProjectileType = EProjectileTypes::Frozen;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AT7FreezeProjectile> FreezeProjectile;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AT7LevitateProjectile> LevitateProjectile;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AT7StickyProjectile> StickyProjectile;	

	UPROPERTY(EditAnywhere)
	FTransform ShootTransform;

	UPROPERTY(EditAnywhere)
	FVector ProjectileSpawnPosition;

	UFUNCTION(BlueprintCallable)
	void SetGunToSticky();

	UFUNCTION(BlueprintCallable)
	void SetGunToUseFreeze();
	
	UFUNCTION(BlueprintCallable)
	void SetGunToUseLevitate();

	UFUNCTION()
	void ShootLevitateProjectile(FTransform SpawnTransform, FVector ForwardVector);

	UFUNCTION()
	void ShootFreezeProjectile(FTransform SpawnTransform, FVector ForwardVector);

	UFUNCTION()
	void ShootStickyProjectile(FTransform SpawnTransform, FVector ForwardVector);
};