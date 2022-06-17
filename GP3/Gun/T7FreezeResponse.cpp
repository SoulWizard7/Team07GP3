#include "T7FreezeResponse.h"
#include "T7AmmoComponent.h"

UT7FreezeResponse::UT7FreezeResponse()
{
	
}

void UT7FreezeResponse::StartFreeze()
{
	//bIsFrozen = true;
	OnStartFreeze.Broadcast();
}

void UT7FreezeResponse::StopFreeze()
{
	//bIsFrozen = false;
	OnStopFreeze.Broadcast();
}
