#include "T7ProjectileMovementComponent.h"

UT7ProjectileMovementComponent::UT7ProjectileMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UT7ProjectileMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	PC->AddForce(AdjustedGravity);
}

void UT7ProjectileMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	AActor* Owner = GetOwner();
}

void UT7ProjectileMovementComponent::SetPrimitiveComponent(UPrimitiveComponent* PrimitiveComponent)
{
	PC = PrimitiveComponent;
}
