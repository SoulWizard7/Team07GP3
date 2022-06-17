#pragma once

#include "GameFramework/Actor.h"
#include "T7LevitateProjectile.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS(Meta = (BlueprintSpawnableComponent))
class AT7LevitateProjectile : public AActor
{
	GENERATED_BODY()
public:
	AT7LevitateProjectile();

	UPROPERTY()
	bool hasImpacted = false;

	UFUNCTION()
	void BeginOverlapHandle(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	USphereComponent* SphereComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMeshComponent;

	UFUNCTION(BlueprintImplementableEvent)
	void ProjectileHit();

	UFUNCTION(BlueprintImplementableEvent)
	void ProjectileHitNoHitResponse();
	
};