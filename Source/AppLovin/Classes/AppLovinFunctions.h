
#pragma once

#include "AppLovinFunctions.generated.h"



UCLASS(NotBlueprintable)
class UAppLovinFunctions : public UObject {
	GENERATED_BODY()
	
public:

#if PLATFORM_ANDROID
	static void InitJavaFunctions();
#endif


	// rewarded video

	/**Check if AppLovin Has a rewarded video*/
	UFUNCTION(BlueprintPure, meta = (Keywords = "applovin ad advertising video"), Category = "Applovin|Rewarded Video")
	static bool AppLovinHasRewardedVideo();

	/**AppLovin Show a Rewarded video*/
	UFUNCTION(BlueprintCallable, meta = (Keywords = "applovin ad advertising video"), Category = "Applovin|Rewarded Video")
	static void AppLovinShowRewardedVideo();

	/**AppLovin Preload a Rewarded video*/
	UFUNCTION(BlueprintCallable, meta = (Keywords = "applovin ad advertising video"), Category = "Applovin|Rewarded Video")
	static void AppLovinPreloadRewardedVideo();

};
