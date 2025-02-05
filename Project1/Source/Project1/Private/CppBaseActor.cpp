// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();

	InitLocation = FVector(0.0f, 0.0f, 0.0f);
	//ShowActorInformation();
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// show log information
void ACppBaseActor::ShowActorInformation() {
	
	UE_LOG(LogTemp, Display, TEXT("Instance name : % s"), *ActorName);
  //UE_LOG(LogTemp, Display, TEXT("Instance name : % s"), *UKismetSystemLibrary::GetObjectName(this));
	//UE_LOG(LogTemp, Display, TEXT("PalyerName: %s"), *PlayerName);
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);

}

void ACppBaseActor::SinMovement()
{
	const float Time = GetWorld()->GetTimeSeconds();

	const float NewX = InitLocation.X;
	const float NewY = InitLocation.Y;
	const float NewZ = Amplitude * FMath::Sin(Time * Frequency);

	 CurrLocation = InitLocation + FVector(NewX, NewY, NewZ);
	// GetOwner()->SetActorLocation(CurrLocation);
	this->SetActorLocation(CurrLocation);
}

