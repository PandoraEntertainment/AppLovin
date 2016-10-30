
#pragma once

#include "AppLovinFunctions.h"
#include "AppLovinComponent.generated.h"

UCLASS(ClassGroup=Advertising, HideCategories=(Activation, "Components|Activation", Collision), meta=(BlueprintSpawnableComponent))
class UAppLovinComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:

	//Ad Received
	DECLARE_MULTICAST_DELEGATE(FAppLovinadReceivedDelegate);

	static FAppLovinadReceivedDelegate DidAppLovinadReceivedDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAppLovinadReceivedDynDelegate);

	UPROPERTY(BlueprintAssignable)
	FAppLovinadReceivedDynDelegate DidAppLovinadReceived;

	//Ad Failed to received
	DECLARE_MULTICAST_DELEGATE(FAppLovinfailedToReceiveAdDelegate);

	static FAppLovinfailedToReceiveAdDelegate DidAppLovinfailedToReceiveAdDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAppLovinfailedToReceiveAdDynDelegate);

	UPROPERTY(BlueprintAssignable)
	FAppLovinfailedToReceiveAdDynDelegate DidAppLovinfailedToReceiveAd;

	//Rewarded video completed
	DECLARE_MULTICAST_DELEGATE(FAppLovinDidCompleteRewardedVideoDelegate);

	static FAppLovinDidCompleteRewardedVideoDelegate DidAppLovinCompleteRewardedVideoDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAppLovinDidCompleteRewardedVideoDynDelegate);

	UPROPERTY(BlueprintAssignable)
	FAppLovinDidCompleteRewardedVideoDynDelegate DidAppLovinCompleteRewardedVideo;


	//Ad Hidden
	DECLARE_MULTICAST_DELEGATE(FAppLovinadHiddenDelegate);

	static FAppLovinadHiddenDelegate DidAppLovinadHiddenDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAppLovinadHiddenDynDelegate);

	UPROPERTY(BlueprintAssignable)
	FAppLovinadHiddenDynDelegate DidAppLovinadHidden;




	void OnRegister() override;
	void OnUnregister() override;
	
private:	

	void DidAppLovinCompleteRewardedVideo_Handler() { DidAppLovinCompleteRewardedVideo.Broadcast(); }

	void DidAppLovinadReceived_Handler() { DidAppLovinadReceived.Broadcast(); }

	void DidAppLovinfailedToReceiveAd_Handler() { DidAppLovinfailedToReceiveAd.Broadcast(); }

	void DidAppLovinadHidden_Handler() { DidAppLovinadHidden.Broadcast(); }

	

};
