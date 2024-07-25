// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_ActorGC.h"
#include "HAL/ThreadManager.h"
#include "UE5Coro.h"
#include "Serialization/BufferWriter.h"
using namespace  UE5Coro;
// Sets default values
ATest_ActorGC::ATest_ActorGC()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATest_ActorGC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATest_ActorGC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATest_ActorGC::Test_1()
{
	ptr_obj = NewObject<UGCObject>();
}

void ATest_ActorGC::Test_2()
{
	ptr_obj2 = TStrongObjectPtr<UGCObject>( NewObject<UGCObject>());
	ptr_obj2_1 = ptr_obj2;
	//ptr_obj3 = MakeShareable<UGCObject>(NewObject<UGCObject>());
	//ptr_obj2->AddToRoot()
	//ptr_obj2.add
}
void ATest_ActorGC::Test_2_Null()
{
	ptr_obj2= nullptr;	
}

void ATest_ActorGC::Test_3()
{
	//UE::Tasks::FTaskEvent Event{ UE_SOURCE_LOCATION };
	TWeakObjectPtr<UGCObject> ptr2 =  NewObject<UGCObject>(this);
	UE_LOG(LogTemp, Log, TEXT("Hello Tasks__%d"),ptr2->IsRooted());
	
	
	ptr2->AddToRoot();
	ptr2->AddToRoot();
	
	/*
	ptr2->AddToCluster()*/
	
	UE_LOG(LogTemp, Log, TEXT("Hello Tasks__%d"),ptr2->IsRooted());
	auto tk	=UE::Tasks::Launch(
	UE_SOURCE_LOCATION,
	[ptr2,this]
	{
		UE_LOG(LogTemp, Log, TEXT("Hello Tasks 1"));
		FPlatformProcess::Sleep(2.0f);
		UE_LOG(LogTemp, Log, TEXT("Hello Tasks 2"));
		if (ptr2->IsSafeForRootSet())
		{
			UE_LOG(LogTemp, Log, TEXT("ptr2有效"));
			ptr2->RemoveFromRoot();
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("ptr2无效"));
		}
	});
}
void ATest_ActorGC::Test_4()
{
	Test_4_1();
	/*
	TSharedPtr<UObject> ptr3 = MakeShared<UObject>();//用不了
	auto tk	=UE::Tasks::Launch(
	UE_SOURCE_LOCATION,
	[ptr3,this]
	{
		UE_LOG(LogTemp, Log, TEXT("Hello Tasks 1"));
		FPlatformProcess::Sleep(2.0f);
		UE_LOG(LogTemp, Log, TEXT("Hello Tasks 2"));
		if (ptr3.IsValid())
		{
			UE_LOG(LogTemp, Log, TEXT("ptr3有效"));
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("ptr3无效"));
		}
	});
	*/
}
void ATest_ActorGC::Test_5()
{
	Test_5_1();
}
void ATest_ActorGC::Test_6()
{
	Test_6_1();
	/*
	auto gc_obj= NewObject<UGCObject>(GetTransientPackage());
	UE_LOG(LogTemp, Log, TEXT("Test_6结束"));*/
}


void Test6_1_1()
{
	TWeakObjectPtr<UGCObject> gc_obj= NewObject<UGCObject>(GetTransientPackage());
}

UE5Coro::TCoroutine<> ATest_ActorGC::Test_6_1()
{
	TPromise<int> result;
	auto tk	= UE::Tasks::Launch(
UE_SOURCE_LOCATION,
	[&result,this]
	{
		UE_LOG(LogTemp, Log, TEXT("Hello Tasks 1"));
		FPlatformProcess::Sleep(1.0f);
		result.SetValue(10);
	});
	auto ret = co_await result.GetFuture();

	if (!IsInGameThread())
	{
		co_await UE5Coro::Async::MoveToThread(ENamedThreads::GameThread);
	}
	ON_SCOPE_EXIT
	{
  		UE_LOG(LogTemp, Warning, TEXT("Destroying coroutine stack UTestCoroObj"));
		TWeakObjectPtr<UGCObject> gc_obj = NewObject<UGCObject>(GetTransientPackage());
	    if (gc_obj.IsValid())
	    {
	    	gc_obj->MarkAsGarbage();
	    }
		//this->GetWorld()->Endtick
		//方案一这个时候才启动UE的GC
		//++GFrameCounter;
		//TStrongObjectPtr<> 方案2 使用强指针。但必须在主线程
		//TWeakObjectPtr 方案3 使用弱指针，必须手动GC
		
		
	};
	
	UE_LOG(LogTemp, Log, TEXT("结束Test_ActorGC"));
}
 

class TArrayBytes : TArray<uint8>
{
public:
	TArrayBytes()
	{
		UE_LOG(LogTemp, Log, TEXT("TArrayBytes"));
	}
	~TArrayBytes()
	{
		UE_LOG(LogTemp, Log, TEXT("~TArrayBytes"));
	}
	
};
UE5Coro::TCoroutine<int> ATest_ActorGC::Test_5_1()
{
	TSharedPtr<TArray<uint8>> ptr = MakeShareable(new TArray<uint8>);
	TSharedPtr<TArrayBytes> ptr2=MakeShareable(new TArrayBytes);
	ptr->Push(5);
	TPromise<int> result;
	UE_LOG(LogTemp, Log, TEXT("Hello Tasks  0"));
	auto tk	= UE::Tasks::Launch(
UE_SOURCE_LOCATION,
	[&ptr,&result,this]
	{
		UE_LOG(LogTemp, Log, TEXT("Hello Tasks 1"));
		FPlatformProcess::Sleep(4.0f);
		
		UE_LOG(LogTemp, Log, TEXT("Hello Tasks %d"), (*ptr)[0] );
		result.SetValue(10);
	});
	auto ret = co_await result.GetFuture();
	UE_LOG(LogTemp, Log, TEXT("Hello Tasks 3%d"),(*ptr)[0]);
	co_return ret;
	
	/*
	TArray<uint8> ay;
	ay.Push(5);
	TPromise<int> result;
	UE_LOG(LogTemp, Log, TEXT("Hello Tasks  0"));
	auto tk	= UE::Tasks::Launch(
UE_SOURCE_LOCATION,
	[&ay,&result,this]
	{
		UE_LOG(LogTemp, Log, TEXT("Hello Tasks 1"));
		FPlatformProcess::Sleep(4.0f);
		UE_LOG(LogTemp, Log, TEXT("Hello Tasks %d"),ay[0]);
		result.SetValue(10);
	});
	auto ret = co_await result.GetFuture();
	UE_LOG(LogTemp, Log, TEXT("Hello Tasks 3%d"),ay[0]);
	co_return ret;
	*/
}

UE5Coro::TCoroutine<int> ATest_ActorGC::Test_4_1()
{
	TPromise<int > result;
	TWeakObjectPtr<UGCObject> ptr2 =  NewObject<UGCObject>(this);//这次测试证明UEGC为每帧删除
	ptr2->AddToRoot();
	auto tk	=UE::Tasks::Launch(
UE_SOURCE_LOCATION,
	[&result,&ptr2,this]
	{
		UE_LOG(LogTemp, Log, TEXT("Hello Tasks 1"));
		FPlatformProcess::Sleep(4.0f);
		UE_LOG(LogTemp, Log, TEXT("Hello Tasks 2"));
		if (ptr2.IsValid())
		{
			UE_LOG(LogTemp, Log, TEXT("ptr2有效"));
			ptr2->RemoveFromRoot();
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("ptr2无效"));
		}
		result.SetValue(10);
	});

	co_await result.GetFuture();
	ptr2->RemoveFromRoot();
	UE_LOG(LogTemp, Log, TEXT("Hello Tasks 3"));

	co_return 5;
	//co_return co_await result.GetFuture();
	//co_return co_await result.GetFuture();
}





void ATest_ActorGC::ReleaseGC()
{
	//++GFrameCounter;
	GEngine->ForceGarbageCollection(); // 下一帧执行GC
}
