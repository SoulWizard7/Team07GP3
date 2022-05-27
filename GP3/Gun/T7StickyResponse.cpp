#include "T7StickyResponse.h"

UT7StickyResponse::UT7StickyResponse()
{
	
}

void UT7StickyResponse::StartSticky()
{
	bIsSticky = true;
	OnStartSticky.Broadcast();
}

void UT7StickyResponse::StopSticky()
{
	bIsSticky = false;
	OnStopSticky.Broadcast();
}
