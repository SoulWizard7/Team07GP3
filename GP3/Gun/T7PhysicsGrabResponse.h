#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "T7PhysicsGrabResponse.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GP3_API UT7PhysicsGrabResponse : public UActorComponent
{
	GENERATED_BODY()

public:
	UT7PhysicsGrabResponse();
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ClampMin = 0, ClampMax = 100))
	float Mass;

	UPROPERTY()
	class USoundCue* SoundCue;
};
