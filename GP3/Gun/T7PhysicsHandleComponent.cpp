#include "T7PhysicsHandleComponent.h"

#include "T7PhysicsGrabResponse.h"

UT7PhysicsHandleComponent::UT7PhysicsHandleComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UT7PhysicsHandleComponent::TriggerGrab(UPrimitiveComponent* PrimitiveComponent)
{
	GrabbedComponent = PrimitiveComponent;
	const UT7PhysicsGrabResponse* GrabResponse = GrabbedComponent->GetOwner()->FindComponentByClass<UT7PhysicsGrabResponse>();
	if (GrabResponse == nullptr) return;

	GrabbedComponent->WakeRigidBody();
	bIsDrag = GrabResponse->Mass >= MassForDrag;

	if (!bIsDrag)
	{
		GrabComponentAtLocation(PrimitiveComponent, NAME_None, PrimitiveComponent->GetComponentLocation());
	}
}

void UT7PhysicsHandleComponent::TriggerDrop()
{
	ReleaseComponent();
}

void UT7PhysicsHandleComponent::SetDragLocation(FVector Location)
{
	if (GrabbedComponent == nullptr)
	{
		return;
	}
	FVector Direction = Location - GrabbedComponent->GetComponentLocation();
	GrabbedComponent->AddForce(Direction * DragForce);

	DrawDebugLine(GetWorld(),
		Location,
		GrabbedComponent->GetComponentLocation(),
		FColor::Red,
		false,
		0);
}

void UT7PhysicsHandleComponent::SetObjectLocationAndRotation(FVector Location, FRotator Rotation)
{
	if (bIsDrag)
	{
		SetDragLocation(Location);
	}
	else
	{
		SetTargetLocationAndRotation(Location, Rotation);
	}
}
