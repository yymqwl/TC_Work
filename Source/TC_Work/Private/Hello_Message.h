// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "IMessage.h"
#include "UObject/Object.h"
#include "Hello_Message.generated.h"

/**
 * SpecifierX = 33
 */
UCLASS( meta=( Test2 ="12312" ,Test3=22))
class TC_WORK_API UHello_Message : public UObject,public IMessage 
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (DisplayName = "Hello Message"))
	FString Msg;
};
