#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyActorNest.h" // Include the header file, not the source file
#include "MyHUDNest.generated.h" // This should match the class name

UCLASS()
class ANESTARDUINO_API AMyHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void DrawHUD() override;
};

// Always include this last
#include "MyHUDNest.generated.h"
