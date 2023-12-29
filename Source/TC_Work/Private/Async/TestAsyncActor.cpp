// Fill out your copyright notice in the Description page of Project Settings.


#include "TestAsyncActor.h"

// Sets default values
ATestAsyncActor::ATestAsyncActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
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
	// 获取输入组件
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

