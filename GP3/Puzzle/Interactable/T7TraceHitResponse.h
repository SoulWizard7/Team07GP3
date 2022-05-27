#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "T7TraceHitResponse.generated.h"

UCLASS(ClassGroup="Puzzle", meta=(BlueprintSpawnableComponent))
class GP3_API UT7TraceHitResponse : public UActorComponent
{
	GENERATED_BODY()

public:
	UT7TraceHitResponse();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHitEnter);
	UPROPERTY(BlueprintAssignable)
	FOnHitEnter OnHitEnter;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHitExit);
	UPROPERTY(BlueprintAssignable)
	FOnHitExit OnHitExit;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHitStay);
	UPROPERTY(BlueprintAssignable)
	FOnHitStay OnHitStay;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteract);
	UPROPERTY(BlueprintAssignable)
	FOnInteract OnInteract;

	UFUNCTION(BlueprintCallable, DisplayName="TriggerEnter")
	void TriggerEnter();

	UFUNCTION(BlueprintCallable, DisplayName="TriggerExit")
	void TriggerExit();

	UFUNCTION(BlueprintCallable, DisplayName="TriggerStay")
	void TriggerStay();

	UFUNCTION(BlueprintCallable, DisplayName="TriggerInteract")
	void TriggerInteract();
};
