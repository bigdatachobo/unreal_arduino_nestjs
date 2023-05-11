#include "MyActorNest.h"
#include "WebSocketBlueprintLibrary.h" // Import WebSocketBlueprintLibrary

// Sets default values
AMyActorNest::AMyActorNest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyActorNest::BeginPlay()
{
	Super::BeginPlay();

	// Create WebSocket connection
	WebSocket = UWebSocketBlueprintLibrary::Connect(TEXT("ws://localhost:3000"));

	// Bind WebSocket data received event
	WebSocket->OnReceiveData.AddDynamic(this, &AMyActorNest::HandleWebSocketDataReceived);
}

// Called every frame
void AMyActorNest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Method to handle WebSocket data
void AMyActorNest::HandleWebSocketDataReceived(const FString& Data)
{
	UE_LOG(LogTemp, Warning, TEXT("Received: %s"), *Data);
	WebSocketData = Data; // Store the received data
}
