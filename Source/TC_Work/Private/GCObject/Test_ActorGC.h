// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GCObject.h"
#include "GameFramework/Actor.h"
#include "UE5Coro/Coroutine.h"
#include "UE5Coro.h"
#include "Test_ActorGC.generated.h"

UCLASS(BlueprintType,Blueprintable)
class TC_WORK_API ATest_ActorGC : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATest_ActorGC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	virtual void Test_1();
	UFUNCTION(BlueprintCallable)
	virtual void Test_2();
	UFUNCTION(BlueprintCallable)
	virtual void Test_2_Null();
	UFUNCTION(BlueprintCallable)
	virtual void Test_3();

	UFUNCTION(BlueprintCallable)
	virtual void Test_4();

	UFUNCTION(BlueprintCallable)
	virtual void Test_5();
	UFUNCTION(BlueprintCallable)
	virtual void Test_6();

	UE5Coro::TCoroutine<> Test_6_1();
	UE5Coro::TCoroutine<int>  Test_5_1();
	
	UE5Coro::TCoroutine<int> Test_4_1(); 
	UFUNCTION(BlueprintCallable)
	virtual void ReleaseGC();


	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	UPROPERTY()
	TObjectPtr<UGCObject> ptr_obj;
	TStrongObjectPtr<UGCObject> ptr_obj2;
	TStrongObjectPtr<UGCObject> ptr_obj2_1;//不支持跨线程，只支持主线程和GC回收线程
	TSharedPtr<UGCObject> ptr_obj3;

	//FObjectPtr ptr_obj2;
	//FObjectPtr<UGCObject> ptr_obj2;
};
