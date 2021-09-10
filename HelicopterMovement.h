
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "HelicopterMovement.generated.h"

UCLASS()
class MYPROJECT_API AHelicopterMovement : public APawn
{
	GENERATED_BODY()

public:
	AHelicopterMovement();

protected:
	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* HelicopterMesh;
	
	bool bFly;
	void Fly(float Value);
	void Vertical(float Value);
	void MouseY(float Value);
	void MouseX(float Value);
};
