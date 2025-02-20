// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/BaseCharacter.h"

#include "CanvasTypes.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Layout/Visibility.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement=true;
	GetCharacterMovement()->RotationRate=FRotator(0.f,500.f,0.f);
	
	SpringArm=CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(GetRootComponent());
	
	SpringArm->bUsePawnControlRotation = true;
	
	Camera=CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	AbilitySystemComponent=CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	BaseAttributes=CreateDefaultSubobject<UBaseAttributeSet>(TEXT("BaseAttributes"));
	
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BaseAttributes->GetHealthAttribute()).
		AddUObject(this,&ABaseCharacter::OnHealthChangedNative);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BaseAttributes->GetStamiaAttribute()).
		AddUObject(this,&ABaseCharacter::OnStamiaChangedNative);
	}
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystem()
{
	return AbilitySystemComponent;
}

void ABaseCharacter::OnHealthChangedNative(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.OldValue, Data.NewValue);
}

void ABaseCharacter::OnStamiaChangedNative(const FOnAttributeChangeData& Data)
{
	OnStamiaChanged(Data.OldValue, Data.NewValue);
}
