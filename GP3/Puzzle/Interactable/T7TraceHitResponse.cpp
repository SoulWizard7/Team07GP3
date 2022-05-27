#include "T7TraceHitResponse.h"

UT7TraceHitResponse::UT7TraceHitResponse()
{
}

void UT7TraceHitResponse::TriggerEnter()
{
	OnHitEnter.Broadcast();
}

void UT7TraceHitResponse::TriggerExit()
{
	OnHitExit.Broadcast();
}

void UT7TraceHitResponse::TriggerStay()
{
	OnHitStay.Broadcast();
}

void UT7TraceHitResponse::TriggerInteract()
{
	OnInteract.Broadcast();
}
