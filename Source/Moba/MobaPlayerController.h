// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/PlayerController.h"
#include "Interactable.h"
#include "MobaPlayerController.generated.h"

class AMobaAIController;

UCLASS()
class AMobaPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMobaPlayerController();	

protected:
	/**/
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite)
	AMobaAIController *AIController;

	/** Navigate player to the given world location. */
	UFUNCTION(BlueprintNativeEvent)
	void SetNewMoveDestination(const FVector DestLocation);

	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	//The team this Player Controller belongs to
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Team")
		ETeam Team;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();

	/** Begins cast of player's first ability */
	void CastAbility1();
};


