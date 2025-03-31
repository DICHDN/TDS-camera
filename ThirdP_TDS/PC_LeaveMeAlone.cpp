// LeaveMeAlone Game by Netologiya. All RightsReserved.


#include "PC_LeaveMeAlone.h"

APC_LeaveMeAlone::APC_LeaveMeAlone()
{

}

void APC_LeaveMeAlone::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}
