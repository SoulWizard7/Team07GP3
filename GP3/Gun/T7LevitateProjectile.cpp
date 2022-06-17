#include "T7LevitateProjectile.h"

#include "T7LevitateResponse.h"
#include "Components/SphereComponent.h"

AT7LevitateProjectile::AT7LevitateProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	RootComponent = SphereComponent;

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AT7LevitateProjectile::BeginOverlapHandle);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(SphereComponent);
}

void AT7LevitateProjectile::BeginOverlapHandle(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(hasImpacted) return;
	hasImpacted = true;
	
	FString msg1 = OtherActor->GetHumanReadableName();
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.f, FColor::White, msg1, true, FVector2D(1.f));
	
	UT7LevitateResponse* LevitateResponse = OtherActor->FindComponentByClass<UT7LevitateResponse>();

	if(LevitateResponse != nullptr)
	{
		LevitateResponse->StartLevitate();
		ProjectileHit();
	}
	else
	{
		ProjectileHitNoHitResponse();
	}
	
}
