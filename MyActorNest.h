#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

UCLASS()
class ANESTARDUINO_API AMyActorNest : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyActorNest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// WebSocket
	class UWebSocketBase* WebSocket;

	void HandleWebSocketDataReceived(const FString& Data);
};

// Always include this last
#include "MyActorNest.generated.h"
