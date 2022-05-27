#pragma once

#include "GameFramework/Actor.h"
#include "T7FreezeProjectile.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS(Meta = (BlueprintSpawnableComponent))
class AT7FreezeProjectile : public AActor
{
	GENERATED_BODY()
public:
	AT7FreezeProjectile();

	UFUNCTION()
	void BeginOverlapHandle(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

	UFUNCTION(BlueprintImplementableEvent)
	void ProjectileHit();
	
};