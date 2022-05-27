#pragma once
#include "Components/ActorComponent.h"
#include "T7LevitateResponse.generated.h"

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
	
	UFUNCTION(BlueprintCallable)
	void StartLevitate();
	
	UFUNCTION(BlueprintCallable)
	void StopLevitate();

	UPROPERTY(BlueprintReadOnly)
	bool bIsLevitating;
};