//  LeaveMeAlone Game by Netologiya. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LMACoinPickup.generated.h"

 //DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCoinPickupDelgate);

class USphereComponent;
class UStaticMeshComponent;
class URotatingMovementComponent;

UCLASS()
class LEAVEMEALONE_API ALMACoinPickup : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALMACoinPickup();

	/*UPROPERTY(BLueprintAssignable, Category = "CoinPickup")
	FOnCoinPickupDelgate OnCoinPickup;*/

	UFUNCTION()
	void OnBeginOverlapComponentEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Counter")
	int CoinAmount;

protected:
	UPROPERTY(VisibleAnywhere, Category = "CoinPickup")
	TObjectPtr<USphereComponent> ColliderComponent;

	UPROPERTY(EditDefaultsOnly, Category = "CoinPickup")
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	UPROPERTY(EditDefaultsOnly, Category = "CoinPickup")
	TObjectPtr<URotatingMovementComponent> RotatingMovementComponent;

	// Side of the Collider, the bigger this is the further away from
	// the Coin mesh the player can pick it up
	UPROPERTY(EditDefaultsOnly, Category = "CoinPickup")
	float ColliderRadius = 32.0f;

	/*UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int TotalCoinAmount = 8;*/

	/*void IncrementCoins();
	bool IfCoinEmpty() const;*/

	virtual void BeginPlay() override;
};
