#pragma once
#include "Components/ActorComponent.h"
#include "T7StickyResponse.generated.h"

class UT7AmmoComponent;
class AGP3Character;

UCLASS(ClassGroup = ProjectileResponse, Meta = (BlueprintSpawnableComponent))
class UT7StickyResponse : public UActorComponent
{
	GENERATED_BODY()
public:
	UT7StickyResponse();

	// Events
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartSticky);
	UPROPERTY(BlueprintAssignable)
	FOnStartSticky OnStartSticky;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStopSticky);
	UPROPERTY(BlueprintAssignable)
	FOnStopSticky OnStopSticky;

	// Triggers
	UFUNCTION(BlueprintCallable)
	void StartSticky();
	
	UFUNCTION(BlueprintCallable)
	void StopSticky();

	UPROPERTY(BlueprintReadWrite)
	bool bIsSticky;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AGP3Character> player;
};