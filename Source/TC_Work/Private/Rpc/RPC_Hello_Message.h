// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RPC_Message.h"
#include "RPC_MessageType.h"

#include "RPC_Hello_Message.generated.h"

/**
 * 
 */
UCLASS()
class TC_WORK_API URPC_Hello_Message : public URPC_Message
{
	GENERATED_BODY()
public:
	virtual uint16 GetMessageType() override
	{
		return StaticCast<uint16>(ERPC_MessageType::Hello);
	}
};
