#pragma once
#include "Components/ActorComponent.h"
#include "GP3/GP3Character.h"
#include "T7FreezeResponse.generated.h"

class UT7AmmoComponent;
class AGP3Character;

UCLASS(ClassGroup = ProjectileResponse, Meta = (BlueprintSpawnableComponent))
class UT7FreezeResponse : public UActorComponent
{
	GENERATED_BODY()
public:
	UT7FreezeResponse();

	// Events
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartFreeze);
	UPROPERTY(BlueprintAssignable)
	FOnStartFreeze OnStartFreeze;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStopFreeze);
	UPROPERTY(BlueprintAssignable)
	FOnStopFreeze OnStopFreeze;

	// Triggers
	UFUNCTION(BlueprintCallable)
	void StartFreeze();
	
	UFUNCTION(BlueprintCallable)
	void StopFreeze();

	UPROPERTY(BlueprintReadWrite)
	bool bIsFrozen;
};