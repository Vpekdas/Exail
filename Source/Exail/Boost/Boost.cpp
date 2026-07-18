// Fill out your copyright notice in the Description page of Project Settings.


#include "Boost.h"
#include <Components/StaticMeshComponent.h>
#include <Exail/Player/Drone.h>
#include "Components/BoxComponent.h"
#include <Delegates/Delegate.h>
#include <Templates/Casts.h>

// Sets default values
ABoost::ABoost()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>("CollisionBox");
	RootComponent = CollisionBox;

	BoostMesh = CreateDefaultSubobject<UStaticMeshComponent>("BoostMesh");
	BoostMesh->SetupAttachment(RootComponent);

	CollisionBox->SetGenerateOverlapEvents(true);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ABoost::OnOverlapBegin);

}

// Called when the game starts or when spawned
void ABoost::BeginPlay()
{
	Super::BeginPlay();
}

void ABoost::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ADrone* Drone = Cast<ADrone>(OtherActor))
	{
		Drone->ApplySpeedBoost(1000.f, 5.f);
		Destroy();
	}
}

// Called every frame
void ABoost::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

