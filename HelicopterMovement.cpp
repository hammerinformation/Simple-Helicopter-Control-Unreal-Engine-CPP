

#include "HelicopterMovement.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"


// Github @hammerinformation
AHelicopterMovement::AHelicopterMovement()
{
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	HelicopterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Helicopter"));
	HelicopterMesh->SetupAttachment(RootComponent);

	
}

void AHelicopterMovement::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Error, TEXT("Begin Play Called"));

}


void AHelicopterMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	bFly = GetActorLocation().Z > 65 ? true : false;
}


void AHelicopterMovement::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Fly", this, &AHelicopterMovement::Fly);
	PlayerInputComponent->BindAxis("Vertical", this, &AHelicopterMovement::Vertical);
	PlayerInputComponent->BindAxis("MouseY", this, &AHelicopterMovement::MouseY);
	PlayerInputComponent->BindAxis("MouseX", this, &AHelicopterMovement::MouseX);
}

void AHelicopterMovement::Fly(float Value) {

	if (Value != 0) {

		AddMovementInput(FVector::UpVector, Value * 1000);

	}

}

void AHelicopterMovement::Vertical(float Value) {

	if (Value > 0) {
		AddMovementInput(GetActorForwardVector(), -Value * 1000);
	}

}

void AHelicopterMovement::MouseY(float Value)
{
	if (bFly) {
		AddControllerPitchInput(Value / 3);

	}


}

void AHelicopterMovement::MouseX(float Value)
{

	AddControllerYawInput(Value / 3);


}

