#pragma once





//定义区域
TC_WORK_API DECLARE_LOG_CATEGORY_EXTERN(Game_Log,Log,All);
//////////////////
///定义GF日志
///[Core.Log]
///Game_Log=Display
///控制方法
///
///
///
#define GAME_VeryVerbose(Format, ...) \
UE_LOG(Game_Log,VeryVerbose,Format,##__VA_ARGS__)


#define GAME_Verbose(Format, ...) \
UE_LOG(Game_Log,Verbose,Format,##__VA_ARGS__)

#define GAME_LOG(Format, ...) \
UE_LOG(Game_Log,Log,Format,##__VA_ARGS__)

#define GAME_DISPLAY(Format, ...) \
UE_LOG(Game_Log,Display,Format,##__VA_ARGS__)

#define GAME_WARNING(Format, ...) \
UE_LOG(Game_Log,Warning,Format,##__VA_ARGS__)

#define GAME_ERROR(Format, ...) \
UE_LOG(Game_Log,Error,Format,##__VA_ARGS__)

#define GAME_FATAL(Format, ...) \
UE_LOG(Game_Log,Fatal,Format,##__VA_ARGS__)



///////////////////////////////