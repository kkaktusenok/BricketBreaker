// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle.h"

// Sets default values
APaddle::APaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Padle = CreateDefaultSubobject<UStaticMeshComponent>("SM Padle");
	RootComponent = SM_Padle;

	SM_Padle->SetEnableGravity(false);
	SM_Padle->SetConstraintMode(EDOFMode::XZPlane);
	SM_Padle->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Padle->SetCollisionProfileName("PhysicsActor");

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>("Floating Pawn Movement");
	
}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APaddle::MoveHoHorizontal(float AxisValue)
{
	AddMovementInput(FVector(AxisValue,0.f,0.f),1.f,false);
}

