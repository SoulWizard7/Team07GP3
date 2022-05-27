#pragma once
#include "Components/ActorComponent.h"
#include "T7StickyResponse.generated.h"

UCLASS(ClassGroup = ProjectileResponse, Meta = (BlueprintSpawnableComponent))
class UT7StickyResponse : public UActorComponent
{
	GENERATED_BODY()
public:
	UT7StickyResponse();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartSticky);
	UPROPERTY(BlueprintAssignable)
	FOnStartSticky OnStartSticky;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStopSticky);
	UPROPERTY(BlueprintAssignable)
	FOnStopSticky OnStopSticky;

	UFUNCTION(BlueprintCallable)
	void StartSticky();
	
	UFUNCTION(BlueprintCallable)
	void StopSticky();

	UPROPERTY(BlueprintReadWrite)
	bool bIsSticky;
	
};