//  LeaveMeAlone Game by Netologiya. All Rights Reserved.

#include "LevelActors/LMACoinPickup.h"
#include "Components/SphereComponent.h"
#include "Player/LMADefaultCharacter.h"
#include "GameFramework/Character.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

// Sets default values
ALMACoinPickup::ALMACoinPickup()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ColliderComponent = CreateDefaultSubobject<USphereComponent>("ColliderComponent");
	SetRootComponent(ColliderComponent);

	ColliderComponent->SetSphereRadius(ColliderRadius);
	// We want overlap events to be generated
	ColliderComponent->SetGenerateOverlapEvents(true);
	ColliderComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	// Since we only want to trigger on player we can ignore everything that isn't a Pawn
	ColliderComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	ColliderComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	// Setup OnBeginOverlap Event
	//ColliderComponent->OnComponentBeginOverlap.AddDynamic(this, &ALMACoinPickup::OnBeginOverlapComponentEvent);

	// Static Mesh is required so the user can see the Coin
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");

	// Attach to Collider component so it is always in the center
	MeshComponent->SetupAttachment(GetRootComponent());

	// This does not required collisions so we disable for everything and ignore on everything
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

	// Don't want this to generate overlap events so we disable it
	MeshComponent->SetGenerateOverlapEvents(false);

	RotatingMovementComponent = CreateDefaultSubobject<URotatingMovementComponent>("RotatingMovementComponent");
}



void ALMACoinPickup::OnBeginOverlapComponentEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Using Cast to check if the OtherActor is a Character
	// This should be changed if you have AI walking around

	ALMADefaultCharacter* Char = Cast<ALMADefaultCharacter>(OtherActor);
	if (!Char)
		return;

	Char->AddCoinByValue(1);
	

	//if (OnCoinPickup.IsBound())
	//{
	//	OnCoinPickup.Broadcast();
	//}

	
	// Destroy the Actor so it disappears from the world
	Destroy();
}

void ALMACoinPickup::BeginPlay()
{
	// Call the base class
	Super::BeginPlay();

	// Setup OnBeginOverlap Event
	ColliderComponent->OnComponentBeginOverlap.AddDynamic(this, &ALMACoinPickup::OnBeginOverlapComponentEvent);
}

//void ALMACoinPickup::IncrementCoins()
//{
//	CoinAmount++;
//	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, FString::Printf(TEXT("Coins = %f"), CoinAmount));
//
//	if (IfCoinEmpty())
//	{
//		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, FString::Printf(TEXT("Level is empty"), CoinAmount));
//	}
//}
//
//bool ALMACoinPickup::IfCoinEmpty() const
//{
//	if ((TotalCoinAmount - CoinAmount) == 0)
//		return true;
//	else
//		return false;
//}
