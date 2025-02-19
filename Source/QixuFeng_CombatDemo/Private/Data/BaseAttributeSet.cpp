// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/BaseAttributeSet.h"
#include "GameplayEffectExtension.h"


void UBaseAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	if(Data.EvaluatedData.Attribute==GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(),0.f,GetMaxHealth()));
	}
	if(Data.EvaluatedData.Attribute==GetStamiaAttribute())
	{
		SetStamia(FMath::Clamp(GetStamia(),0.f,GetMaxStamia()));
	}
}
