// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UENUM(BlueprintType)
enum class EMovementState : uint8
{
    Mobility,
    Static
};

USTRUCT(BlueprintType)
struct FTransformStruct
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector CurrentLocation = FVector::ZeroVector;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FRotator CurrentRotation = FRotator::ZeroRotator;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};

UCLASS()
class NETLES_API AMyActor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AMyActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere)

    FString PlayerName = "Nik";

    UPROPERTY(VisibleAnywhere)

    UStaticMeshComponent* Mesh;

    UPROPERTY(EditAnywhere)

    int EnemyNum = 20;

    UPROPERTY(EditDefaultsOnly)

    float CurrentHealth = 57.54687;

    UPROPERTY(EditInstanceOnly)

    bool IsAlive = true;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

protected:
    UFUNCTION(BlueprintCallable)
    void ShowInformation();
};
