// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

UCLASS()
class PROJECT1_API ACppBaseActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACppBaseActor();
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//UPROPERTY(EditAnywhere)
	//FString PlayerName = GetOwner()->GetName();  // "A_CppBase_0";
	FString ActorName = this->GetName();


	UPROPERTY(EditAnywhere)
	int EnemyNum = 20;

	UPROPERTY(EditInstanceOnly)
	bool IsAlive = true;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	FVector	InitLocation;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	FVector	CurrLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere)
	float Amplitude = 70.0;

	UPROPERTY(EditAnywhere)
	float Frequency = 4.0;

	UFUNCTION(BlueprintCallable)
	void SinMovement();


	UFUNCTION(BlueprintCallable)
	void ShowActorInformation();


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
