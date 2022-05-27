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

	void TriggerImpulse();

	UPROPERTY()
	FVector ForwardVector = FVector::ZeroVector;

	UPROPERTY(BlueprintReadOnly)
	FVector Velocity = FVector::ZeroVector;

	UPROPERTY(EditAnywhere)
	float UpDirection = 0.0f;

	UPROPERTY(EditAnywhere)
	float Speed = 0.0f;
	
	
};
