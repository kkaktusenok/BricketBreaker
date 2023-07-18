// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"

#include "Ball.h"

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>("Brick");
	SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	Box_Collision = CreateDefaultSubobject<UBoxComponent>("Box Collision");
	Box_Collision->SetBoxExtent(FVector(25.f,10.f,10.f));

	RootComponent = Box_Collision;
}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();

	Box_Collision->OnComponentBeginOverlap.AddDynamic(this,&ABrick::OnOverlapBegin);
}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABrick::OnOverlapBegin(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherActorIndexType, bool bFromSpeed, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Ball"))
	{
		ABall* MyBall = Cast<ABall>(OtherActor);
		
		FVector BallVelocity = MyBall->GetVelocity();
		BallVelocity *= (SpeedModifierOnBounce - 1.f);

		MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity,true);

		FTimerHandle UnusedHAndle;
		GetWorldTimerManager().SetTimer(UnusedHAndle,this,&ABrick::DestroyBrick,0.1f,false);
	}
}

void ABrick::DestroyBrick()
{
	this->Destroy();
}


