// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AMessage.h"
#include "IMessage.h"
#include "UObject/Object.h"
#include "Ping_Message.generated.h"

/**
 * 
 */
UCLASS()
class TC_WORK_API UPing_Message : public UAMessage//public UObject ,public IMessage
{
	GENERATED_BODY()
public:
	UPROPERTY()
	FDateTime DateTime;
};
