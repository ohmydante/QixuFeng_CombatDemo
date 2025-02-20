// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "Data/BaseAttributeSet.h"
#include "BaseCharacter.generated.h"

UCLASS()
class QIXUFENG_COMBATDEMO_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	UAbilitySystemComponent* AbilitySystemComponent;

	void OnHealthChangedNative(const FOnAttributeChangeData& Data);
	void OnStamiaChangedNative(const FOnAttributeChangeData& Data);


	UFUNCTION(BlueprintImplementableEvent,Category="Ability")
	void OnHealthChanged(float OldValue,float NewValue);
	UFUNCTION(BlueprintImplementableEvent,Category="Ability")
	void OnStamiaChanged(float OldValue,float NewValue);

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystem();

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	class UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	UBaseAttributeSet* BaseAttributes;
};


