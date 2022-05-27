#include "T7InteractableProcessor.h"
#include "T7InteractableComponent.h"
#include "T7InteractableResponse.h"

UT7InteractableProcessor::UT7InteractableProcessor()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UT7InteractableProcessor::EvaluateCallResult()
{
	// AND processor
	bool bAndFlag = false;
	for (const auto Input : InputInteractables)
	{

		const UT7InteractableComponent* InteractableComp = Input->FindComponentByClass<UT7InteractableComponent>();
		check(InteractableComp);

		bAndFlag = InteractableComp->bIsActivated;

		if (bAndFlag == false)
		{
			TriggerDeactivate();
			return;
		};
	}
	TriggerActivate();
}

void UT7InteractableProcessor::TriggerActivate()
{
	if (OutputResponses.Num() == 0) return;
	
	for (const auto Output : OutputResponses)
	{
		if (Output == nullptr) continue;
		
		const UT7InteractableResponse* InteractableResp = Output->FindComponentByClass<UT7InteractableResponse>();
		if (InteractableResp == nullptr) continue;

		InteractableResp->OnActivate.Broadcast();
	}
}

void UT7InteractableProcessor::TriggerDeactivate()
{
	if (OutputResponses.Num() == 0) return;
	
	for (const auto Output : OutputResponses)
	{
		if (Output == nullptr) continue;
		
		const UT7InteractableResponse* InteractableResp = Output->FindComponentByClass<UT7InteractableResponse>();
		if (InteractableResp == nullptr) continue;

		InteractableResp->OnDeactivate.Broadcast();
	}
}

