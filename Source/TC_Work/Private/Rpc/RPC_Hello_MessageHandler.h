// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameLog.h"
#include "Hello_Message.h"
#include "RPC_Hello_Message.h"
#include "RPC_Message.h"
#include "UObject/Object.h"
#include "RPC_Hello_MessageHandler.generated.h"

/**
 * 
 */
UCLASS()
class TC_WORK_API URPC_Hello_MessageHandler_S : public URPC_MessageHandler
{
	GENERATED_BODY()
public:
	virtual uint64 Get_Rpc_Ability() override
	{
		return 1;
	}
	virtual TSubclassOf<class URPC_Message> Get_Rpc_Request_Class() override
	{
		return URPC_Hello_Message_C2S::StaticClass();
	}
	virtual TSubclassOf<class URPC_Message> Get_Rpc_Reply_Class() override
	{
		return URPC_Hello_Message_S2C::StaticClass();
	}
	virtual TObjectPtr<URPC_Message> Process(TObjectPtr<URPC_Message> rpc_request) override
	{
		auto  rpc_reply = Super::Process(rpc_request);
		if (IsValid(rpc_reply))
		{
			auto  hello_msg_reply =Cast<URPC_Hello_Message_S2C>(rpc_reply);
			check(hello_msg_reply);
			auto  hello_request =Cast<URPC_Hello_Message_C2S>(rpc_request);
			check(hello_request);
			hello_msg_reply->Msg = FString::Printf(TEXT("%s处理之后"),*hello_request->Msg);
			GAME_LOG(TEXT("URPC_Hello_MessageHandler: %s"),*hello_msg_reply->Msg);
			
		}
		return rpc_reply;
	}
};

UCLASS()
class TC_WORK_API URPC_Hello_MessageHandler_C : public URPC_MessageHandler
{
	GENERATED_BODY()
public:
	virtual uint64 Get_Rpc_Ability() override
	{
		return 2;
	}
	virtual TSubclassOf<class URPC_Message> Get_Rpc_Request_Class() override
	{
		return URPC_Hello_Message_S2C::StaticClass();
	}
	virtual TSubclassOf<class URPC_Message> Get_Rpc_Reply_Class() override
	{
		return URPC_Hello_Message_S2C::StaticClass();
	}
	virtual TObjectPtr<URPC_Message> Process(TObjectPtr<URPC_Message> rpc_request) override
	{
		auto  rpc_reply = Super::Process(rpc_request);
		if (IsValid(rpc_reply))
		{
			auto  hello_msg =Cast<URPC_Hello_Message_S2C>(rpc_reply);
			
			GAME_LOG(TEXT("URPC_Hello_MessageHandler_Client: %s"),*hello_msg->Msg);
		}
		return rpc_reply;
	}
};
