#include "T7StickyResponse.h"

#include "T7AmmoComponent.h"
#include "GP3/GP3Character.h"
#include "Kismet/GameplayStatics.h"

UT7StickyResponse::UT7StickyResponse()
{
	
}

void UT7StickyResponse::StartSticky()
{
	//bIsSticky = true;
	OnStartSticky.Broadcast();
}

void UT7StickyResponse::StopSticky()
{
	//bIsSticky = false;
	OnStopSticky.Broadcast();
}
