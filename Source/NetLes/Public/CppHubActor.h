// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppHubActor.generated.h"

class AMyActor;

UCLASS()
class NETLES_API ACppHubActor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ACppHubActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere)
    float SpawnTimerRate = 2.0f;

    UPROPERTY(EditAnywhere)
    float DestroyTimerRate = 1.0f;

    UPROPERTY()
    TArray<AMyActor*> SpawnedObjects;

    UPROPERTY(EditAnywhere)
    TSubclassOf<AMyActor> CppClass;

    FTimerHandle SpawnTimerHandle;
    FTimerHandle DestroyTimerHandle;

    void onTimeToSpawn();
    void onTimeToDestroy();

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

private:
    const int32 TotalCount = 10;
    int32 CurrentTimerCount = 0;
};
