#include "T7FreezeProjectile.h"
#include "T7FreezeResponse.h"

#include "Components/SphereComponent.h"

AT7FreezeProjectile::AT7FreezeProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	RootComponent = SphereComponent;

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AT7FreezeProjectile::BeginOverlapHandle);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(SphereComponent);
	
}

void AT7FreezeProjectile::BeginOverlapHandle(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(hasImpacted) return;
	hasImpacted = true;
	
	FString msg1 = OtherActor->GetHumanReadableName();
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.f, FColor::White, msg1, true, FVector2D(1.f));
	
	
	UT7FreezeResponse* FreezeResponse = OtherActor->FindComponentByClass<UT7FreezeResponse>();

	if(FreezeResponse != nullptr)
	{		
		FreezeResponse->StartFreeze();
		ProjectileHit();
	}
	else
	{
		ProjectileHitNoHitResponse();
	}
	
}


