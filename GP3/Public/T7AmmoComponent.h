#pragma once
#include "T7AmmoComponent.generated.h"

UCLASS(ClassGroup=(Custom),meta=(BlueprintSpawnableComponent))
class UT7AmmoComponent : public UActorComponent
{

	GENERATED_BODY()

public:

	UT7AmmoComponent();

	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable)
	void RemoveFreezeAmmo();
	UFUNCTION(BlueprintCallable)
	void AddFreezeAmmo();

	UFUNCTION(BlueprintCallable)
	void RemoveStickyAmmo();
	UFUNCTION(BlueprintCallable)
	void AddStickyAmmo();

	UFUNCTION(BlueprintCallable)
	void RemoveLevitateAmmo();
	UFUNCTION(BlueprintCallable)
	void AddLevitateAmmo();

	// Events
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRemoveFreezeAmmo);
	UPROPERTY(BlueprintAssignable)
	FOnRemoveFreezeAmmo OnRemoveFreezeAmmo;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAddFreezeAmmo);
	UPROPERTY(BlueprintAssignable)
	FOnAddFreezeAmmo OnAddFreezeAmmo;


	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRemoveStickyAmmo);
	UPROPERTY(BlueprintAssignable)
	FOnRemoveStickyAmmo OnRemoveStickyAmmo;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAddStickyAmmo);
	UPROPERTY(BlueprintAssignable)
	FOnAddStickyAmmo OnAddStickyAmmo;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRemoveLevitateAmmo);
	UPROPERTY(BlueprintAssignable)
	FOnRemoveLevitateAmmo OnRemoveLevitateAmmo;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAddLevitateAmmo);
	UPROPERTY(BlueprintAssignable)
	FOnAddLevitateAmmo OnAddLevitateAmmo;

	UFUNCTION(BlueprintCallable)
	void ReplenishAmmo();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int FreezeAmmo = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int LevitateAmmo = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int StickyAmmo = 1;

	UPROPERTY(BlueprintReadWrite)
	int MaxFreezeAmmo = 2;

	UPROPERTY(BlueprintReadWrite)
	int MaxLevitateAmmo = 3;

	UPROPERTY(BlueprintReadWrite)
	int MaxStickyAmmo = 1;

	// Effected objects
	UPROPERTY(BlueprintReadOnly)
	int EffectedSticky;

	UPROPERTY(BlueprintReadOnly)
	int EffectedLevitate;

	UPROPERTY(BlueprintReadOnly)
	int EffectedFreeze;
};