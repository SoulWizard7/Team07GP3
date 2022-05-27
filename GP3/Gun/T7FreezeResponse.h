#pragma once
#include "Components/ActorComponent.h"
#include "T7FreezeResponse.generated.h"

UCLASS(ClassGroup = ProjectileResponse, Meta = (BlueprintSpawnableComponent))
class UT7FreezeResponse : public UActorComponent
{
	GENERATED_BODY()
public:
	UT7FreezeResponse();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartFreeze);
	UPROPERTY(BlueprintAssignable)
	FOnStartFreeze OnStartFreeze;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStopFreeze);
	UPROPERTY(BlueprintAssignable)
	FOnStopFreeze OnStopFreeze;

	UFUNCTION(BlueprintCallable)
	void StartFreeze();
	
	UFUNCTION(BlueprintCallable)
	void StopFreeze();

	UPROPERTY(BlueprintReadWrite)
	bool bIsFrozen;
	
};