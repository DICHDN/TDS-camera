// LeaveMeAlone Game by Netologiya. All RightsReserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PC_LeaveMeAlone.generated.h"

/**
 * 
 */
UCLASS()
class THIRDP_TDS_API APC_LeaveMeAlone : public APlayerController
{
	GENERATED_BODY()

	public:
	APC_LeaveMeAlone();

	protected:
	virtual void BeginPlay() override;
	
};
