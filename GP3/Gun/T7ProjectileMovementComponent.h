#pragma once

#include "Components/ActorComponent.h"
#include "T7ProjectileMovementComponent.generated.h"

UCLASS(Meta = (BlueprintSpawnableComponent))
class UT7ProjectileMovementComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	
	UT7ProjectileMovementComponent();

	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SetPrimitiveComponent(UPrimitiveComponent* PrimitiveComponent);
	
public:
	UPROPERTY(BlueprintReadWrite)
	UPrimitiveComponent* PC;
	
	UPROPERTY(BlueprintReadWrite)
	FVector AdjustedGravity;

	UPROPERTY(EditAnywhere)
	float Speed = 0.0f;
};
