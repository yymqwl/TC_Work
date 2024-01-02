// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpServer1.h"

#include "GameLog.h"
#include "HttpManager.h"
#include "HttpPath.h"
#include "HttpRouteHandle.h"
#include "HttpServerModule.h"
#include "IHttpRouter.h"
#include "Profile/TC_Profile.h"


// Sets default values
AHttpServer1::AHttpServer1()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHttpServer1::BeginPlay()
{
	GAME_LOG(TEXT("HttpServer BeginPlay"));
	Super::BeginPlay();
	const uint32 HttpRouterPort = 8080;
	//const uint32 InvalidHttpRouterPort = TNumericLimits<uint16>::Max() + 1; // 65536
	const FHttpPath HttpPath(TEXT("/TestHttpServer"));
	TSharedPtr<IHttpRouter> HttpRouter = FHttpServerModule::Get().GetHttpRouter(HttpRouterPort);

	Log_CurrentThread(TEXT("当前线程1"));
	// Ensure we can create route bindings
	const FHttpRequestHandler RequestHandler = [this]
	(const FHttpServerRequest& Request, const FHttpResultCallback& OnComplete)
	{
		GAME_LOG(TEXT("回复"));
		Log_CurrentThread(TEXT("当前线程2"));
		TUniquePtr<FHttpServerResponse> response = FHttpServerResponse::Create(TEXT("HttpServerExample GET"),TEXT("text/html"));
		OnComplete(MoveTemp(response));
		return true;
	};
	
	FHttpRouteHandle HttpRouteHandle = HttpRouter->BindRoute(HttpPath, EHttpServerRequestVerbs::VERB_GET, RequestHandler);

	FHttpServerModule::Get().StartAllListeners();
	
}
void AHttpServer1::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	FHttpServerModule::Get().StopAllListeners();
}

// Called every frame
void AHttpServer1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

