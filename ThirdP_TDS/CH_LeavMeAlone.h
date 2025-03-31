// LeaveMeAlone Game by Netologiya. All RightsReserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/DecalComponent.h"
#include "CH_LeavMeAlone.generated.h"


class UCameraComponent;
class USpringArmComponent;

UCLASS()
class THIRDP_TDS_API AC_LeavMeAlone : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AC_LeavMeAlone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;
	UPROPERTY()
	UDecalComponent* CurrentCursor = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	UMaterialInterface* CursorMaterial = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	FVector CursorSize = FVector(20.0f, 40.0f, 40.0f);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void ZoomCameraDown(); // приближение удаление камеры
	void ZoomCameraUp();
	

private:

	float YRotation = -75.0f; // – отвечает за поворот камеры по оси Y
	float ArmLength = 1400.0f;//	– отвечает за длину штатива.
	float FOV = 55.0f; //	– отвечает за поле зрения камеры. угол обзора
	float ZoomSpeed = 50.0f; // скорость изменения камеры (в данном проекте без применения дополнительного актора камеры)
	void MoveForward(float Value); // движение вперед/назад
	void MoveRight(float Value);   // движение в лево / в право
	



};
