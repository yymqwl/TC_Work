// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IMessage.h"
#include "UObject/Object.h"
#include "Hello_Message.generated.h"

/**
 * 
 */
UCLASS()
class TC_WORK_API UHello_Message : public UObject,public IMessage 
{
	GENERATED_BODY()
public:
	UPROPERTY()
	float Msg;
};
