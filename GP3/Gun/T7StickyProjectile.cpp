#include "T7StickyProjectile.h"

#include "T7StickyResponse.h"
#include "Components/SphereComponent.h"

AT7StickyProjectile::AT7StickyProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	RootComponent = SphereComponent;

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AT7StickyProjectile::BeginOverlapHandle);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(SphereComponent);
}

void AT7StickyProjectile::BeginOverlapHandle(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(hasImpacted) return;
	hasImpacted = true;
	
	FString msg1 = OtherActor->GetHumanReadableName();
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.f, FColor::White, msg1, true, FVector2D(1.f));
	
	UT7StickyResponse* StickyResponse = OtherActor->FindComponentByClass<UT7StickyResponse>();

	if(StickyResponse != nullptr)
	{
		StickyResponse->StartSticky();
		ProjectileHit();
	}
	else
	{
		ProjectileHitNoHitResponse();
	}
	
}
