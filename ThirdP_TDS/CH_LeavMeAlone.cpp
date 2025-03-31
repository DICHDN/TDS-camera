// LeaveMeAlone Game by Netologiya. All RightsReserved.


#include "CH_LeavMeAlone.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
// Sets default values
AC_LeavMeAlone::AC_LeavMeAlone()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	SpringArmComponent->SetUsingAbsoluteRotation(true); // данное условие не позволит нашей камере поворачиваться в момент поворота персонажа.В жанре Top - Down Shooter, камера обычно находится статично над игроком
	SpringArmComponent->TargetArmLength = ArmLength; // присваиваем длину штатива
	SpringArmComponent->SetRelativeRotation(FRotator(YRotation, 0.0f, 0.0f)); // структура FRotator хранит аргументы в следующей последовательности : Pitch, Yaw, Roll.Так как нам необходимо определить значения по оси Y, мы устанавливаем Pitch аргумент
	SpringArmComponent->bDoCollisionTest = false; // проверка коллизий
	SpringArmComponent->bEnableCameraLag = false;	  // используется ли лаг камеры для сглаживания "дерганья" камеры
	CameraComponent->SetFieldOfView(FOV); // установка угла обзора камеры
	CameraComponent->bUsePawnControlRotation = false; //– данное условие запрещаем камере вращаться относительно SpringArmComponent.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	

}

// Called when the game starts or when spawned
void AC_LeavMeAlone::BeginPlay()
{
	Super::BeginPlay();
	
	if (CursorMaterial)
	{
		CurrentCursor = UGameplayStatics::SpawnDecalAtLocation(GetWorld(), CursorMaterial, CursorSize, FVector(0));
	}
}

// Called every frame
void AC_LeavMeAlone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PC)
	{
		FHitResult ResultHit;
		PC->GetHitResultUnderCursor(ECC_GameTraceChannel1, true, ResultHit);
		float FindRotatorResultYaw = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), ResultHit.Location).Yaw;
		SetActorRotation(FQuat(FRotator(0.0f, FindRotatorResultYaw, 0.0f)));
		if (CurrentCursor)
		{
			CurrentCursor -> SetWorldLocation(ResultHit.Location); 
		}
	}
}

// Called to bind functionality to input
void AC_LeavMeAlone::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AC_LeavMeAlone::MoveForward); // движение в перед/назад
	PlayerInputComponent->BindAxis("MoveRight", this, &AC_LeavMeAlone::MoveRight);	   // движение в лево/право
	
	PlayerInputComponent->BindAction("ZoomCameraUp", IE_Pressed, this, &AC_LeavMeAlone::ZoomCameraUp);	// приближение камеры
	PlayerInputComponent->BindAction("ZoomCameraDown", IE_Pressed, this, &AC_LeavMeAlone::ZoomCameraDown); // приближение камеры
}

void AC_LeavMeAlone::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}
void AC_LeavMeAlone::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}
void AC_LeavMeAlone::ZoomCameraUp()
{
	
		ArmLength = FMath::Clamp(ArmLength - ZoomSpeed, 500.0f, 1400.0f); // Ограничение
		//UE_LOG(LogTemp, Warning, TEXT("New ArmLength: %f"), ArmLength);
		SpringArmComponent->TargetArmLength = ArmLength;
		
}

void AC_LeavMeAlone::ZoomCameraDown()
{
	
		ArmLength = FMath::Clamp(ArmLength + ZoomSpeed, 500.0f, 1400.0f); // Ограничение
		//UE_LOG(LogTemp, Warning, TEXT("New ArmLength: %f"), ArmLength);
		SpringArmComponent->TargetArmLength = ArmLength;
		
}



