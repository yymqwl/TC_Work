// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestAsyncActor.generated.h"

UCLASS(Blueprintable)
class ATestAsyncActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestAsyncActor();

	/*
	UFUNCTION()
	void OnKeyPressed(FKey Key);
	*/

	UFUNCTION(BlueprintCallable)
	void Test1();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;


	virtual void TestAsync1();
	virtual void PrintThreadLog(FString str="");
	//virtual void NotifyActorOnClicked(FKey ButtonPressed) override;
	//virtual void DestroyPlayerInputComponent();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
