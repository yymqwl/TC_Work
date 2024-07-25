// Fill out your copyright notice in the Description page of Project Settings.


#include "TestRpcActor.h"

#include "GameLog.h"
#include "RPC_Hello_Message.h"

// Sets default values
ATestRpcActor::ATestRpcActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestRpcActor::BeginPlay()
{
	Super::BeginPlay();

	FString host = TEXT("127.0.0.1");
	uint32 port = 8100;
	
	Ptr_Server = NewObject<UAsio2_Rpc_Server>(this);
	Ptr_Server->Init();
	Ptr_Server->Create_RPC_MessageHandler_Map(1);
	Ptr_Server->Bind_Start(host,port);
	
	
	Ptr_Client = NewObject<UAsio2_Rpc_Client>(this);
	Ptr_Client->Create_RPC_MessageHandler_Map(2);
	Ptr_Client->Connect_Start(host,port);
	
	//Server->Init();
}

void ATestRpcActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if (Ptr_Server!=nullptr)
	{
		Ptr_Server->Stop();
		Ptr_Server = nullptr;

	}
	if (Ptr_Client!=nullptr)
	{
		Ptr_Client->Stop();
		Ptr_Client = nullptr;
	}
}


void ATestRpcActor::Call_Test()
{

	Call_Test_Coroutine();
	/*
	auto rpc_msg = NewObject<URPC_Hello_Message_C2S>();
	//
	
	TC_RPC::TC_RPC_Message msg {.MessageType =100 };
	
	msg.Data = NewObject<URPC_Message>();
	if (Ptr_Client!=nullptr)
	{
		auto  rpc_msg_reply = co_await Ptr_Client->Request( MoveTemp(rpc_msg));
		
		//Ptr_Client->Test_Client_Request( TWeakObjectPtr<URPC_Message>(NewObject<URPC_Message>() ));	
	}
	*/
}
void ATestRpcActor::Call_Test2()
{
	Ptr_Client->Test_Client_Request2();
}
void ATestRpcActor::Call_Test3()
{
	auto rpc_hello_c2s =NewObject<URPC_Hello_Message_C2S>();
	rpc_hello_c2s->Msg = TEXT("Call_Test3 Msg");
	Ptr_Client->Test_Client_Request(rpc_hello_c2s);
}


TCoroutine<> ATestRpcActor::Call_Test_Coroutine()
{
	
	auto rpc_msg = NewObject<URPC_Hello_Message_C2S>();
	rpc_msg->Tag = TEXT("Test_1");
	if (Ptr_Client!=nullptr)
	{
		auto  rpc_msg_reply = co_await Ptr_Client->Request( rpc_msg);
		if (IsValid(rpc_msg_reply) )
		{
			GAME_LOG(TEXT("Call_Test_Coroutine %s"),*rpc_msg_reply->GetClass()->GetName());
			auto  hello_rpc_msg_reply=Cast<URPC_Hello_Message_S2C>(rpc_msg_reply);
			if (IsValid(hello_rpc_msg_reply))
			{
				GAME_LOG(TEXT("Hello_rpc_msg_reply %s"),*hello_rpc_msg_reply->Msg);
			}
		}
		else
		{
			GAME_LOG(TEXT("Call_Test_Coroutine Null"));
		}
		//Ptr_Client->Test_Client_Request( TWeakObjectPtr<URPC_Message>(NewObject<URPC_Message>() ));	
	}
}
void ATestRpcActor::GC_Test()
{
	GEngine->ForceGarbageCollection(); // 下一帧执行GC
}



// Called every frame
void ATestRpcActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

