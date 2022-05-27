#pragma once
#include "CoreMinimal.h"
#include "T7Debug.h"
#include "T7PhysicsBlueprintLibrary.generated.h"


UCLASS()
class GP3_API UT7PhysicsBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION()
	static float sqr(float Value)
	{
		return Value * Value;
	}
	
	UFUNCTION(BlueprintCallable, Category="Projectiles")
	static float GetAngleRadians(float Range, float MaxHeight, float Gravity = 980.f)
	{
		return atan((4*MaxHeight)/Range);
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Projectiles")
	static float GetAngleDegrees(float Range, float MaxHeight, float Gravity = 980.f)
	{
		return atan((4*MaxHeight)/Range) * 180/PI;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Projectiles")
	static float GetImpulseFromRadians(const float MaxHeight, const float AngleRadians, const float Gravity = 980.f)
	{
		return sqrtf((2*Gravity*MaxHeight)/sqr(sinf(AngleRadians)));
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Projectiles")
	static float GetImpulseFromDegrees(const float MaxHeight, const float AngleDegrees, const float Gravity = 980.f)
	{
		return sqrtf((2*Gravity*MaxHeight)/sqr(sinf(AngleDegrees*(PI/180.f))));
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Projectiles")
	static FVector GetAdjustedGravity(const FVector AimUpVector, const float Gravity = 980.f)
	{
		return -AimUpVector * Gravity;
	}
};