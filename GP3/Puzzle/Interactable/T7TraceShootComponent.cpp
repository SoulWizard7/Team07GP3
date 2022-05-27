#include "T7TraceShootComponent.h"

#include "T7TraceHitResponse.h"

UT7TraceShootComponent::UT7TraceShootComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UT7TraceShootComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UT7TraceShootComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UT7TraceShootComponent::LineTraceShoot(FVector Location, FVector Direction, ECollisionChannel TraceChannel)
{
	FHitResult TraceHit;
	GetWorld()->LineTraceSingleByChannel(TraceHit, Location, Location + Direction, TraceChannel);

	if (TraceHit.bBlockingHit)
	{
		UT7TraceHitResponse* HitResponse = TraceHit.GetActor()->FindComponentByClass<UT7TraceHitResponse>();

		// OnHitEnter
		if (HitResponse != nullptr && HoveredHitResponse == nullptr)
		{
			HoveredHitResponse = HitResponse;
			HoveredHitResponse->TriggerEnter();
		}
		// OnHitStay
		if (HitResponse != nullptr && HoveredHitResponse != nullptr)
		{
			HoveredHitResponse->TriggerStay();
		}
		// One object to another without exiting
		if (HitResponse != nullptr && HoveredHitResponse != nullptr && HitResponse != HoveredHitResponse)
		{
			HoveredHitResponse->TriggerExit();
			HoveredHitResponse = HitResponse;
			HoveredHitResponse->TriggerEnter();
		}
	}
	// OnHitExit
	else if (HoveredHitResponse != nullptr)
	{
		HoveredHitResponse->TriggerExit();
		HoveredHitResponse = nullptr;
	}
}