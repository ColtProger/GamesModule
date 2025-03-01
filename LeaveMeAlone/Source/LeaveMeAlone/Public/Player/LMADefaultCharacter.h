//  LeaveMeAlone Game by Netologiya. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LMADefaultCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class ULMAHealthComponent;
class UAnimMontage;


UCLASS()
class LEAVEMEALONE_API ALMADefaultCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALMADefaultCharacter();

	UFUNCTION()
	ULMAHealthComponent* GetHealthComponent() const { return HealthComponent; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;

	UPROPERTY()
	UDecalComponent* CurrentCursor = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components|Health")
	ULMAHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	UMaterialInterface* CursorMaterial = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	FVector CursorSize = FVector(20.0f, 40.0f, 40.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ArmLengthMin = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ArmLengthMax = 2000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxWalkSpeed = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxStamina = 100.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	UAnimMontage* DeathMontage;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	float YRotation = -75.0f;

	//float ArmLengthMax = 2400.0f;
	//float ArmLengthMin = 400.0f;
	float ArmLength = 1000.0f;

	float ZoomFactor;
	bool bZoomingIn;

	float FOV = 55.0f;

	float SprintSpeed = 600.0f;
	float RunSpeed = 300.0f;
	
	float Stamina = MaxStamina;
	bool ifSprinting = false;

	void MoveForward(float Value);
	void MoveRight(float Value);

	void SetMouseWheelUp();
	void SetMouseWheelDown();
	//void SetDestination(float ZoomFactor);

	void OnDeath();
	void RotationPlayerOnCursor();
	void OnHealthChanged(float NewHealth);

	void SprintStart();
	void SprintEnd();
	//void OnStaminaChanged(int Stamina);

	//int GetStamina();

	void DrainStamina();
	void RegenStamina();
};
