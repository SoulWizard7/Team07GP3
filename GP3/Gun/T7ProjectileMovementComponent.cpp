#include "T7ProjectileMovementComponent.h"

UT7ProjectileMovementComponent::UT7ProjectileMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UT7ProjectileMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	
}

void UT7ProjectileMovementComponent::BeginPlay()
{
	Super::BeginPlay();		
}

void UT7ProjectileMovementComponent::TriggerImpulse()
{
	AActor* Owner = GetOwner();
	// thought is to get owner and set direction and velocity from owner (gun?) plus a bunch of variables
	Velocity = ForwardVector + FVector(0,0,UpDirection);

	UPrimitiveComponent* PC = Owner->FindComponentByClass<UPrimitiveComponent>();

	FString msg2 = Velocity.ToString();
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.f, FColor::Green, msg2, true, FVector2D(1.f));
	
	if(PC != nullptr)
	{		
		PC->AddImpulse(Velocity * Speed);
	}
	else
	{
		FString msg4 = FString::Printf(TEXT ("Add Impulse failed"));
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.f, FColor::Red, msg4, true, FVector2D(1.f));
	}	
}
