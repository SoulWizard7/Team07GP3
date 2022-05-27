#pragma once
#include "CoreMinimal.h"
#include "T7TraceHitResponse.h"
#include "Components/ActorComponent.h"
#include "T7TraceShootComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GP3_API UT7TraceShootComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UT7TraceShootComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void LineTraceShoot(FVector Location, FVector Direction, ECollisionChannel TraceChannel = ECC_WorldStatic);

public:
	UPROPERTY(BlueprintReadOnly, VisibleInstanceOnly)
	UT7TraceHitResponse* HoveredHitResponse;
};
