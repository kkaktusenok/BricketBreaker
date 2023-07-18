// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Paddle_Player_Controller.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "BallBounds.generated.h"

class UBoxComponent;
class APaddle_Player_Controller;

UCLASS()
class BRICKETBREAKER_API ABallBounds : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallBounds();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	UBoxComponent* Box_Collision;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherActorIndexType, bool bFromSpeed,
	const FHitResult& SweepResult);
	
	APaddle_Player_Controller* PlayerController_Reference;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
