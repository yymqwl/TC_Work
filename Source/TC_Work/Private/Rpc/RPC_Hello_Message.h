// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RPC_Message.h"
#include "RPC_MessageType.h"
#include "GameLog.h"
#include "RPC_Hello_Message.generated.h"

/**
 * 
 */
UCLASS()
class TC_WORK_API URPC_Hello_Message_C2S : public URPC_Message
{
	GENERATED_BODY()
	URPC_Hello_Message_C2S()
	{
		GAME_LOG(TEXT("URPC_Hello_Message_C2S()"));
	}
	virtual  ~URPC_Hello_Message_C2S() override
	{
		GAME_LOG(TEXT("~URPC_Hello_Message_C2S() %s"),*Tag);
	}
public:
	virtual uint16 GetMessageType() override
	{
		return StaticCast<uint16>(ERPC_MessageType::Hello_C2S);
	}

	UPROPERTY()
	FString Msg;
	FString Tag;
};




UCLASS()
class TC_WORK_API URPC_Hello_Message_S2C : public URPC_Message
{
	GENERATED_BODY()
public:
	URPC_Hello_Message_S2C()
	{
		GAME_LOG(TEXT("URPC_Hello_Message_S2C()"));
	}
	virtual  ~URPC_Hello_Message_S2C() override
	{
		GAME_LOG(TEXT("~URPC_Hello_Message_S2C()"));
	}
	virtual uint16 GetMessageType() override
	{
		return StaticCast<uint16>(ERPC_MessageType::Hello_S2C);
	}
	UPROPERTY()
	FString Msg;
};
