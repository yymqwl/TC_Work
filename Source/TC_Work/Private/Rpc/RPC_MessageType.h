#pragma once
#include "RPC_MessageType.generated.h"
//消息类型
//uint16
UENUM()
enum class ERPC_MessageType : uint16
{
	None = 0,
	Hello_C2S,
	Hello_S2C,
	Max
};
ENUM_CLASS_FLAGS(ERPC_MessageType)