// Fill out your copyright notice in the Description page of Project Settings.


#include "TestAsyncActor.h"

#include "HttpManager.h"
#include "Engine/AssetManager.h"
#include "HAL/ThreadManager.h"



// Sets default values
ATestAsyncActor::ATestAsyncActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	//UAssetManager::GetStreamableManager().LoadSynchronous()
	/*
	if (InputComponent == nullptr)
	{
		InputComponent = CreatePlayerInputComponent();
		if (InputComponent)
		{
			SetupPlayerInputComponent(InputComponent);
			InputComponent->RegisterComponent();
			if (UInputDelegateBinding::SupportsInputDelegate(GetClass()))
			{
				InputComponent->bBlockInput = bBlockInput;
				UInputDelegateBinding::BindInputDelegatesWithSubojects(this, InputComponent);
			}
		}
	}*/
}





// Called when the game starts or when spawned
void ATestAsyncActor::BeginPlay()
{
	Super::BeginPlay();
	TestAsync1();
	// 获取输入组件
}
void ATestAsyncActor::PrintThreadLog(FString str)
{
	uint32 CurrentThreadId = FPlatformTLS::GetCurrentThreadId();
	FString CurrentThreadName = FThreadManager::Get().GetThreadName(CurrentThreadId);
	UE_LOG(LogTemp, Display, TEXT("Thread: %s[%d] %s"), *CurrentThreadName, CurrentThreadId ,*str);
}

//InputComponent  = GetWorld()->GetFirstPlayerController()->InputComponent;
	
//auto input = FindComponentByClass<UEnhancedInputComponent>();
	

//InputComponent = FindComponentByClass<UEnhancedInputComponent>();
/*if (InputComponent == nullptr)
{
	GF_LOG(TEXT(" InputComponent Null"));
	return;
}*/
//check(InputComponent);
//InputComponent->Bind(EKeys::A, , this, &ATestAsyncActor::OnKeyPressed);
/*
void ATestAsyncActor::OnKeyPressed(FKey Key)
{
	GF_LOG(TEXT("A Press"));
}*/

using namespace UE::Tasks;
void ATestAsyncActor::TestAsync1()
{
	PrintThreadLog();
	
	{
	 	FTaskEvent Event{ UE_SOURCE_LOCATION };
		auto tk	=Launch(
		UE_SOURCE_LOCATION,
		[&Event,this]
		{
			Event.Wait();
			PrintThreadLog();
			UE_LOG(LogTemp, Log, TEXT("Hello Tasks!")); 
		});
		FPlatformProcess::Sleep(0.1f);
		UE_LOG(LogTemp, Log, TEXT("%d"),Event.IsCompleted()); 
		UE_LOG(LogTemp, Log, TEXT("%d"),Event.IsAwaitable()); 
		Event.Trigger();
		UE_LOG(LogTemp, Log, TEXT("%d"),Event.IsAwaitable()); 
		UE_LOG(LogTemp, Log, TEXT("%d"),Event.IsCompleted());
	}
	/*
	{	// FTaskEvent can be triggered multiple times
		FTaskEvent Event{ UE_SOURCE_LOCATION };
		Event.Trigger();
		UE_LOG(LogTemp, Log, TEXT("%d"),Event.IsCompleted()); 
		Event.Trigger();
		Event.Trigger();
		UE_LOG(LogTemp, Log, TEXT("%d"),Event.IsCompleted());

		
	}
	{	// basic use-case, postpone waiting so the task is executed first
		std::atomic<bool> Done{ false };
		FTask Task = Launch(UE_SOURCE_LOCATION, [&Done]
		{
			FPlatformProcess::Sleep(3);
			Done = true;
		});
		
		
		while (!Task.IsCompleted())
		{
			FPlatformProcess::Yield();
		}
		Task.BusyWait(FTimespan::FromMilliseconds(1));
	
		UE_LOG(LogTemp, Log, TEXT("%d"),Done.load());
	}
	{
		FTaskEvent TaskEvent{ TEXT("TaskEvent") };
		TArray<FTask> Prereqs
		{

			Launch(TEXT("Task A"), []
			{
				FPlatformProcess::Sleep(1);
				UE_LOG(LogTemp, Log, TEXT("Task A"));
			}),
			Launch(TEXT("Task B"), [] {})

		};
		TaskEvent.AddPrerequisites(Prereqs);

		FTask TaskC = Launch(TEXT("Task C"), [] {});
		FTask TaskD = Launch(TEXT("Task D"), [] {});
		TaskEvent.AddPrerequisites(Prerequisites(TaskC, TaskD));
		
		TaskEvent.Trigger();
		UE_LOG(LogTemp, Log, TEXT("TaskEvent %d"),TaskEvent.IsCompleted());
	}*/

	/*
	{
		FPipe Pipe{ UE_SOURCE_LOCATION };

		FTaskEvent TaskEvent{ TEXT("TaskEvent") };
		TArray<FTask> Prereqs
		{

			Launch(TEXT("Task A"), [this,&Pipe]
			{
				FPlatformProcess::Sleep(1);
				PrintThreadLog();
				Pipe.Launch(UE_SOURCE_LOCATION,[this,&Pipe]
					{
						PrintThreadLog(FString::Format(TEXT("Task A {0}"),{Pipe.IsInContext()} ));
					}).Wait();
				UE_LOG(LogTemp, Log, TEXT("Task A "));
			}),
			Launch(TEXT("Task B"), [this,&Pipe]
			{
				FPlatformProcess::Sleep(1);
				PrintThreadLog();
				Pipe.Launch(UE_SOURCE_LOCATION,[this,&Pipe]
				{
					PrintThreadLog(FString::Format(TEXT("Task B {0}"),{Pipe.IsInContext()} ));
				}).Wait();
				UE_LOG(LogTemp, Log, TEXT("Task B"));
			})

		};
		TaskEvent.AddPrerequisites(Prereqs);
		TaskEvent.Trigger();
		
		UE_LOG(LogTemp, Log, TEXT("TaskEvent %d"),TaskEvent.IsCompleted());
		TaskEvent.Wait();
		UE_LOG(LogTemp, Log, TEXT("TaskEvent %d"),TaskEvent.IsCompleted());
	}
	{	// hold the first piped task execution until the next one is piped to test for non-concurrent execution
		FPipe Pipe{ UE_SOURCE_LOCATION };
		bool bTask1Done = false;
		FTask Task1 = Pipe.Launch(UE_SOURCE_LOCATION, 
			[this,&bTask1Done,&Pipe] 
			{ 
				FPlatformProcess::Sleep(3.f);
				UE_LOG(LogTemp, Log, TEXT("%d_%d"),bTask1Done,Pipe.IsInContext());
				bTask1Done = true;
				PrintThreadLog();
			}
		);
		
		// we can't just check if `Task1` is completed because pipe gets unblocked and so the next piped task can start execution before the
		// previous piped task's comlpetion flag is set
		Pipe.Launch(UE_SOURCE_LOCATION, [&bTask1Done,this,&Pipe]
		{
			UE_LOG(LogTemp, Log, TEXT("%d_%d"),bTask1Done,Pipe.IsInContext());
			PrintThreadLog();
			
		}).Wait();
		UE_LOG(LogTemp, Log, TEXT("%d"),Task1.IsCompleted()); 
	}*/

}


void ATestAsyncActor::Test1()
{
	//SQL_LOG(TEXT("Test1 Call:%f"),	FPlatformTime::Seconds());

	
	

	/*
	TSharedPtr< SQLTableWrapper<FPerson> > f = MakeShareable(new SQLTableWrapper<FPerson>);
	f->Rows.Add( MakeShareable(new SQLRowWrapper<FPerson>()) );
	int x= 33;
	int y ;
	f->Rows[0]->SetValue("Id",&x);
	f->Rows[0]->GetValue("Id",&y);
	GF_LOG(TEXT("插入成功%d"),y );*/
	//FPerson::StaticStruct()
	//f = 44;
	//FVector2d V2= 
	//FSQL_Float  f();
	//auto str = FString::Format(TEXT("{0}:{1}"), {TEXT("11"),TEXT("2222222")});
	//auto str = TestSociActor->PSQLSubsys->GetInsertSQLStr<FPerson>();//FString(TEXT("Test1 Call:"));
	
	//TSubclassOf<FSQLRow> p2 ;
	//p2  = FPerson::StaticStruct();
	//FPerson::StaticStruct()
	//p2->IsChildOf();
	//TSubclassOf<>
	
	//TSharedPtr<SQLRowWrapper<FPerson>> p2 = MakeShareable(new SQLRowWrapper<FPerson>());
	
	//TestSociActor->PSQLSubsys->Query()
	/*
	TSharedRef<SQLTableWrapper<FPerson>> ptr_tb =MakeShareable(new SQLTableWrapper<FPerson>());
	TSharedRef<SQLRowWrapper<FPerson>>   ptr_row=MakeShareable(new SQLRowWrapper<FPerson>);
	ptr_row->Data.Id = 6;
	ptr_row->Data.Name = FString(TEXT("测试7"));
	//ptr_row->SetValue(FName("Name"), FString(TEXT("测试6")),true);

	//ptr_row->Data.Name = TEXT("测试6");
	ptr_tb.Get().Rows.Add(ptr_row);
	*/

	/*
	TestSociActor->PSQLSubsys->Update<FPerson>(ptr_tb,[]( TSharedRef<SQLTableWrapper<FPerson>> pt_result , TSharedRef<FSoci_Error> error)
	{
		if (error->HasError())
		{
			return;
		}
		GF_LOG(TEXT("更新成功") );
	});*/
	/*
	
	TestSociActor->PSQLSubsys->Insert<FPerson>(ptr_tb,[]( TSharedRef<SQLTableWrapper<FPerson>> pt_result , TSharedRef<FSoci_Error> error)
		{
			if (error->HasError())
			{
				return;
			}
			SOCI_LOG(TEXT("插入成功") );
		});
	
	TestSociActor->PSQLSubsys->Insert<FPerson>(ptr_tb,[]( TSharedRef<SQLTableWrapper<FPerson>> pt_result , TSharedRef<FSoci_Error> error)
	{
		if (error->HasError())
		{
			return;
		}
		GF_LOG(TEXT("插入成功") );
	});*/
	//FPerson::StaticStruct()->GetName()
	/*
	str.LeftInline(str.Len()-1);
	str +=")";
	*/
	
	//GF_LOG(TEXT("%s"),*str);
	
	/*
	TestSociActor->PSQLSubsys->Query<FPerson>(TEXT("select * from Person"),[](TSharedPtr<SQLTableWrapper<FPerson>> SqlTable,TSharedPtr<FSoci_Error> error)
	{
		if (error->HasError())
		{
			return;
		}

		for (auto row : SqlTable->Rows)
		{
			GF_LOG(TEXT("Test1 Call From Query :%s"),  *row->Data.Name);
		}
	});*/
	/*
	TestSociActor->PSQLSubsys->Query<FPerson>(TEXT("select * from Person"),[](TSharedPtr<FPerson> p)
	{
		GF_LOG(TEXT("Test1 Call From Query :%s"),  *p->Name );
	});*/
	/*[](TSharedPtr<Person> p)
	{
		GF_LOG(TEXT("Test1 Call From Query :%s"), UTF8_TO_TCHAR( p->Name.c_str()));
	});*/
	/*
	FPerson fp;
	fp.Name = TEXT("测试名称1");
	const UStruct* structClass= FPerson::StaticStruct();
	structClass->ChildProperties;
	
	GF_LOG(TEXT("Test1 Call:%s"),*structClass->GetName());
	//遍历属性
	
	for (TFieldIterator<FProperty> i(FPerson::StaticStruct()); i; ++i)
	{
		FProperty* prop=*i;
		if (prop->IsA(FStrProperty::StaticClass()))//(const FStrProperty* StringProperty = Cast<FStrProperty>(prop) )
		{
			const FStrProperty* StringProperty = CastFieldChecked<FStrProperty>(prop);
			auto str	= StringProperty->GetPropertyValue_InContainer(&fp);
			GF_LOG(TEXT("%s:%s"),*prop->GetNameCPP(),*str);
		}
		//prop->GetValue_InContainer()
		//(*prop).IsA<>()
		GF_LOG(TEXT("Test1 Call %s"),*prop->GetName());
		GF_LOG(TEXT("Test1 Call 2"));
		
	}*/
	//TestSociActor->PSQLSubsys->Ping_SQL();
	/*
	TArray<int> ay ;
	ay.Sort()
	*/
	//ay.Sort()
	//TestSociActor->PSQLSubsys->Ping_SQL()
	/*
	auto ger  = FFunctionGraphTask::CreateAndDispatchWhenReady([]()
	{
		Log_CurrentThread(TEXT("当前线程1"));
		FPlatformProcess::Sleep(3.f);
		Log_CurrentThread(TEXT("当前线程2"));
	});
	// 同时创建多个任务
	FGraphEventArray Tasks;
	Tasks.Add(ger);
	FFunctionGraphTask::CreateAndDispatchWhenReady([]()
	{
		Log_CurrentThread(TEXT("任务完成"));
	},TStatId{},&Tasks,ENamedThreads::GameThread);*/
	//Log_CurrentThread(TEXT("任务下派Test1"));

	//GetGameInstance()->GetSubsystem<>()
}
/*
void ATestAsyncActor::DestroyPlayerInputComponent()
{
	
	if (InputComponent)
	{
		InputComponent->DestroyComponent();
		InputComponent = nullptr;
	}
}
*/


void ATestAsyncActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

// Called every frame
void ATestAsyncActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}