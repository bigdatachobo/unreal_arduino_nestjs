#include "MyHUDNest.h"
#include "MyActorNest.h"
#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

void AMyHUD::DrawHUD()
{
	Super::DrawHUD();

	// Get MyActorNest instance
	AMyActorNest* MyActorNest = Cast<AMyActorNest>(UGameplayStatics::GetActorOfClass(GetWorld(), AMyActorNest::StaticClass()));

	if (MyActorNest != nullptr)
	{
		// Get WebSocket data from MyActorNest
		FString WebSocketData = MyActorNest->GetWebSocketData();

		// Draw WebSocket data on screen
		FVector2D ScreenDimensions = FVector2D(Canvas->SizeX, Canvas->SizeY);
		FVector2D TextPosition = FVector2D(50, 50); // Position at the top of the screen

		DrawText(WebSocketData, FColor::White, TextPosition.X, TextPosition.Y);
	}
}
