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


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Counter")
	int CoinAmount;

	void AddCoinByValue(int Value);


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
	float ArmLengthMin = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ArmLengthMax = 1400.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	UAnimMontage* DeathMontage;

	// sprinting

	void UpdateStamina();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MaxWalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float SprintSpeed = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float RunSpeed = 300.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Counter")
	float Stamina;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float MaxStamina = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float StaminaDrainTime  = 5.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float StaminaRefillTime = 10.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float DelayBeforeRefill = 10.0f;

	float CurrentRefillDelayTime;
	bool bIsSprinting;
	bool bHasStamina;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	

private:

	float YRotation = -75.0f;

	//float ArmLengthMax = 2400.0f;
	//float ArmLengthMin = 400.0f;
	float ArmLength = 400.0f;

	float ZoomFactor;
	bool bZoomingIn;

	float FOV = 65.0f;

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

	//void OnStaminaChanged();

	//int GetStamina();
	//void DrainStamina();
	//void RegenStamina();
	
};
