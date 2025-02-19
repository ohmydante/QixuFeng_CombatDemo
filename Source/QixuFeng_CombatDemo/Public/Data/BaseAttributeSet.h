// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class QIXUFENG_COMBATDEMO_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="CombatSystem")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet,Health)
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="CombatSystem")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet,MaxHealth)
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="CombatSystem")
	FGameplayAttributeData Stamia;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet,Stamia)
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="CombatSystem")
	FGameplayAttributeData MaxStamia;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet,MaxStamia)


	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	
};
