#include "T7LevitateResponse.h"
#include "T7AmmoComponent.h"
#include "GP3/GP3Character.h"
#include "Kismet/GameplayStatics.h"

UT7LevitateResponse::UT7LevitateResponse()
{
}

void UT7LevitateResponse::StartLevitate()
{
	//bIsLevitating = true;
	OnStartLevitate.Broadcast();
}

void UT7LevitateResponse::StopLevitate()
{
	//bIsLevitating = false;
	OnStopLevitate.Broadcast();
}