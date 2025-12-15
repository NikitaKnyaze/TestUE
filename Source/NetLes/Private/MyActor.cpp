// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "Engine/Engine.h"

// Sets default values
AMyActor::AMyActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
    SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMyActor::ShowInformation()
{
    UE_LOG(LogTemp, Display, TEXT("PlayerName: %s"), *PlayerName);
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Purple, PlayerName, true, FVector2D(2.0f, 2.0f));

    UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
    UE_LOG(LogTemp, Display, TEXT("CurrentHealth: %f"), CurrentHealth);
    UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);

    UE_LOG(LogTemp, Display, TEXT("CppBase is here"));
    UE_LOG(LogTemp, Warning, TEXT("CppBase fallse"));
    UE_LOG(LogTemp, Error, TEXT("Error"));
}