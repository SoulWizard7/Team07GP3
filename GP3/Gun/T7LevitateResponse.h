#pragma once
#include "Components/ActorComponent.h"
#include "T7LevitateResponse.generated.h"

class UT7AmmoComponent;
class AGP3Character;

UCLASS(ClassGroup = ProjectileResponse, Meta = (BlueprintSpawnableComponent))
class UT7LevitateResponse : public UActorComponent
{
	GENERATED_BODY()
public:
	UT7LevitateResponse();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartLevitate);
	UPROPERTY(BlueprintAssignable)
	FOnStartLevitate OnStartLevitate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStopLevitate);
	UPROPERTY(BlueprintAssignable)
	FOnStopLevitate OnStopLevitate;
	
	// Triggers
	UFUNCTION(BlueprintCallable)
	void StartLevitate();
	
	UFUNCTION(BlueprintCallable)
	void StopLevitate();
	
	UPROPERTY(BlueprintReadWrite)
	bool bIsLevitating;
};