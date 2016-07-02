// Fill out your copyright notice in the Description page of Project Settings.

#include "EscapeGame.h"
#include "OpenDoorActor.h"


// Sets default values for this component's properties
UOpenDoorActor::UOpenDoorActor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoorActor::BeginPlay()
{
	Super::BeginPlay();
	
	// ... Kode som ikke er generert av Unreal.
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}

void UOpenDoorActor::OpenDoor()
{
	AActor* Owner = GetOwner();
	FRotator NewRotation = FRotator(0.0f, -30.f, 0.0f);
	Owner->SetActorRotation(NewRotation);
}



// Called every frame
void UOpenDoorActor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ... if the ActorThatOPens is in the trigger, open the door.
	
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
	}
}

