// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_LogActor.h"

#include "GameLog.h"
#include "Hello_Message.h"
#include "IMessage.h"
#include "Ping_Message.h"
#include "DynamicMesh/DynamicMesh3.h"
//#include "Log/Log.h"

// Sets default values
ATest_LogActor::ATest_LogActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATest_LogActor::BeginPlay()
{
	Super::BeginPlay();

	auto hello_msg =UHello_Message::StaticClass();
	auto str_meta=  hello_msg->GetMetaData("Test2");
	
	
	GAME_LOG(TEXT("Message: %s"),*str_meta);


	for (TFieldIterator<FProperty> it(hello_msg); it; ++it)
	{
		auto key = it->GetNameCPP();
		str_meta = it->GetMetaData("DisplayName");
		GAME_LOG(TEXT("Message: %s  %s"), *key,*str_meta);
	}



	

	/*
	TArray<UObject*> result;
	//auto hello_msg_1 = NewObject<UHello_Message>();

	
	auto ping_msg =FindObject<UClass>(nullptr,TEXT("/Script/UEGF_Work.Hello_Message"));
	
	if (IsValid(ping_msg))
	{
	
		GAME_LOG(TEXT("Message找到2: %d"),*ping_msg->GetName());
	}
	
	
	auto hello_msg =UHello_Message::StaticClass();
	GAME_LOG(TEXT("Message: %s"),*hello_msg->GetName());

	
	auto all_classs =GetAllDerivedClasses();
	
	GAME_LOG(TEXT("Message: %d"),all_classs.Num());
	if (all_classs.Contains(UMessage::StaticClass()))
	{
		auto msg_class2 = all_classs[UAMessage::StaticClass()];
	}
	*/
	/*
	auto message =GetDefault<UMessage>();
	GetObjectsOfClass()*/
	
	

	/*

	GetObjectsOfClass(UInterface::StaticClass(), result, true);
	GAME_LOG(TEXT("Message:开始 %d"),result.GetSlack());
	
	//UStruct::StaticClass()
	for (auto  obj : result)
	{
		if (!IsValid(obj))
		{
			continue;
		}
		
		if (*obj->GetName() == FString("Hello_Message"))
		{
			GAME_LOG(TEXT("Hello_Message找到"));
		}
		//GAME_LOG(TEXT("Message:%s"),*obj->GetName());
	}*/
	GAME_LOG(TEXT("Message:结束"));
	//GetObjectsOfClass(UMessage::GetClass(), result);
	
	//	=FindObject<IMessage>(ANY_PACKAGE,"IMessage");
	
	//TArray<>
	
	//GAME_LOG_TRACK();
	//UE_LOG(Log_GF,Log,TEXT("ATest_LogActor:%d"),111);
	//GAME_LOG(TEXT("ATest_LogActor:%d"),111);
}

// Called every frame
void ATest_LogActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

