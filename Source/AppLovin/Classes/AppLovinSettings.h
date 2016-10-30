
#pragma once

#include "AppLovinSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class UAppLovinSettings : public UObject
{
	GENERATED_BODY()
	
public:
	UAppLovinSettings(const FObjectInitializer& ObjectInitializer);
	
	// Sdk Id

	UPROPERTY(Config, EditAnywhere, Category = App, meta = (DisplayName = "Sdk Id"))
	FString SdkId;


};
