#include "T7InteractableComponent.h"

#include "T7InteractableProcessor.h"

UT7InteractableComponent::UT7InteractableComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UT7InteractableComponent::TriggerActivate()
{
	bIsActivated = true;
	if (ProcessorActor == nullptr) return;
	
	UT7InteractableProcessor* Processor = ProcessorActor->FindComponentByClass<UT7InteractableProcessor>();
	if (Processor == nullptr) return;
	
	Processor->EvaluateCallResult();
	OnActivate.Broadcast();
}

void UT7InteractableComponent::TriggerDeactivate()
{
	bIsActivated = false;
	if (ProcessorActor == nullptr) return;
	
	UT7InteractableProcessor* Processor = ProcessorActor->FindComponentByClass<UT7InteractableProcessor>();
	if (Processor == nullptr) return;
	
	Processor->EvaluateCallResult();
	OnDeactivate.Broadcast();
}



