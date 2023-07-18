// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle_Player_Controller.h"
#include "Ball.h"
#include "Paddle.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

APaddle_Player_Controller::APaddle_Player_Controller()
{
	
}

void APaddle_Player_Controller::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),ACameraActor::StaticClass(),CameraActors);

	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);

	SpawnNewBall();	
}

void APaddle_Player_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	EnableInput(this);
	InputComponent->BindAxis("MoveHorizontal",this, &APaddle_Player_Controller::MoveHorizontal);
	InputComponent->BindAction("Launch",IE_Pressed,this,&APaddle_Player_Controller::Launch);
}

void APaddle_Player_Controller::MoveHorizontal(float AxisValue)
{
	if (auto MyPawn= Cast<APaddle>(GetPawn()))
	{
		MyPawn->MoveHoHorizontal(AxisValue);
	}
}

void APaddle_Player_Controller::Launch()
{
	MyBall->Launch();
}

void APaddle_Player_Controller::SpawnNewBall()
{
	if (!MyBall) MyBall = nullptr;

	if (BallOBJ)
	{
		MyBall = GetWorld()->SpawnActor<ABall>(BallOBJ,SpawnLocation,SpawnRotation,SpawnInfo);
	}
}
