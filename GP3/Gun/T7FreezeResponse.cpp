#include "T7FreezeResponse.h"

UT7FreezeResponse::UT7FreezeResponse()
{
}

void UT7FreezeResponse::StartFreeze()
{
	bIsFrozen = true;
	OnStartFreeze.Broadcast();
}

void UT7FreezeResponse::StopFreeze()
{
	bIsFrozen = false;
	OnStopFreeze.Broadcast();
}
