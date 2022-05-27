#pragma once

#include "CoreMinimal.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "T7PhysicsHandleComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GP3_API UT7PhysicsHandleComponent : public UPhysicsHandleComponent
{
	GENERATED_BODY()

public:
	UT7PhysicsHandleComponent();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGrab);
	UPROPERTY(BlueprintAssignable)
	FOnGrab OnGrab;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDrop);
	UPROPERTY(BlueprintAssignable)
	FOnDrop OnDrop;
	
	UFUNCTION(BlueprintCallable)
	void TriggerGrab(UPrimitiveComponent* PrimitiveComponent);

	UFUNCTION(BlueprintCallable)
	void TriggerDrop();

	UFUNCTION(BlueprintCallable)
	void SetDragLocation(FVector Location);

	UFUNCTION(BlueprintCallable)
	void SetObjectLocationAndRotation(FVector Location, FRotator Rotation);


public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Range = 200.f;

	UPROPERTY(EditAnywhere)
	float DragForce;

	UPROPERTY(EditAnywhere, meta=(ClampMin=0, ClampMax=100))
	float MassForDrag;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bIsDrag;
};
