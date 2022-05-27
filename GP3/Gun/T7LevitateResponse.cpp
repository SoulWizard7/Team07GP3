#include "T7LevitateResponse.h"

UT7LevitateResponse::UT7LevitateResponse()
{
}

void UT7LevitateResponse::StartLevitate()
{
	bIsLevitating = true;
	OnStartLevitate.Broadcast();
}

void UT7LevitateResponse::StopLevitate()
{
	bIsLevitating = false;
	OnStopLevitate.Broadcast();
}
