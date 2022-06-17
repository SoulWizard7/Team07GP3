#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "T7Character.generated.h"

class UCameraComponent;
class USpringArmComponent;
UCLASS()
class GP3_API AT7Character : public ACharacter
{
	GENERATED_BODY()

public:
	AT7Character();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void AimTracing();

	// To call on begin play
	UFUNCTION(BlueprintCallable, Category="Shooting")
	void SetShootOrigin(USceneComponent* ShootOrigin);
	

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Shooting")
	FVector GetAdjustedUpVector();

	UFUNCTION(BlueprintCallable, Category="Shooting")
	void Shoot();

public:
	// Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UT7PushComponent* PushComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UT7TraceShootComponent* TraceShootComponent;

	UPROPERTY(BlueprintReadWrite)
	USceneComponent* TrajectoryShootOrigin;

	UPROPERTY(BlueprintReadWrite)
	USceneComponent* TrajectoryShootDirection;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UT7ShootProjectile* ShootProjectileComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UT7AmmoComponent* AmmoComponent;

	// Properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	bool bLockMovement;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	bool bLockLook;
	
	UPROPERTY(BlueprintReadOnly, Category="Shooting")
	bool bInShootingRange;
	
	UPROPERTY(BlueprintReadOnly, Category="Shooting")
	FHitResult AimHitResult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Shooting")
	float AimRange;

	UPROPERTY(BlueprintReadOnly, Category="Shooting")
	FVector AimTargetLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Shooting")
	TEnumAsByte<ECollisionChannel> AimCollisionChannel;

	// Aim trajectory parameters
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Shooting")
	float TrajectoryHeight;
	
	UPROPERTY(BlueprintReadOnly, Category="Shooting")
	float TrajectoryRange;

	UPROPERTY(BlueprintReadOnly, Category="Shooting")
	float TrajectoryAngle;

	UPROPERTY(BlueprintReadOnly, Category="Shooting")
	float TrajectoryImpulse;

	UPROPERTY(BlueprintReadOnly, Category="Shooting")
	FVector TrajectoryUpVector;
};
