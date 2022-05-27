#pragma once
#include "CoreMinimal.h"
#include "T7Debug.generated.h"

/* *
	* Added macros to simplify logging
***/
#define LOG(x, ...) UE_LOG(LogTemp, Log, TEXT(x), __VA_ARGS__)
#define LOG_WARNING(x, ...) UE_LOG(LogTemp, Warning, TEXT(x), __VA_ARGS__)
#define LOG_ERROR(x, ...) UE_LOG(LogTemp, Error, TEXT(x), __VA_ARGS__)

UCLASS()
class GP3_API UT7Debug : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION()
	static void LogScreen(const FString DebugMessage, float TimeToDisplay = 1.f, FColor DisplayColor = FColor::White, int32 Key = -1)
	{
		GEngine->AddOnScreenDebugMessage(Key, TimeToDisplay, DisplayColor, DebugMessage);
	}
	UFUNCTION()
	static void LogScreenSecond(const FString DebugMessage, FColor DisplayColor = FColor::White, int32 Key = -1)
	{
		GEngine->AddOnScreenDebugMessage(Key, 1.f, DisplayColor, DebugMessage);
	}
	UFUNCTION()
	static void LogScreenFrame(const FString DebugMessage, FColor DisplayColor = FColor::White, int32 Key = -1)
	{
		GEngine->AddOnScreenDebugMessage(Key, 0.f, DisplayColor, DebugMessage);
	}
};
