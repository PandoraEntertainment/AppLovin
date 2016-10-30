
#include "AppLovinPrivatePCH.h"

void UAppLovinComponent::OnRegister()
{
	Super::OnRegister();
	
	//Rewarded Video

	UAppLovinComponent::DidAppLovinCompleteRewardedVideoDelegate.AddUObject(this, &UAppLovinComponent::DidAppLovinCompleteRewardedVideo_Handler);

	UAppLovinComponent::DidAppLovinadReceivedDelegate.AddUObject(this, &UAppLovinComponent::DidAppLovinadReceived_Handler);

	UAppLovinComponent::DidAppLovinfailedToReceiveAdDelegate.AddUObject(this, &UAppLovinComponent::DidAppLovinfailedToReceiveAd_Handler);

	UAppLovinComponent::DidAppLovinadHiddenDelegate.AddUObject(this, &UAppLovinComponent::DidAppLovinadHidden_Handler);

}

void UAppLovinComponent::OnUnregister()
{
	Super::OnUnregister();
	
	//Rewarded Video

	UAppLovinComponent::DidAppLovinCompleteRewardedVideoDelegate.RemoveAll(this);

	UAppLovinComponent::DidAppLovinadReceivedDelegate.RemoveAll(this);
	
	UAppLovinComponent::DidAppLovinfailedToReceiveAdDelegate.RemoveAll(this);

	UAppLovinComponent::DidAppLovinadHiddenDelegate.RemoveAll(this);
}

//Rewarded Video

UAppLovinComponent::FAppLovinDidCompleteRewardedVideoDelegate UAppLovinComponent::DidAppLovinCompleteRewardedVideoDelegate;

UAppLovinComponent::FAppLovinadReceivedDelegate UAppLovinComponent::DidAppLovinadReceivedDelegate;

UAppLovinComponent::FAppLovinfailedToReceiveAdDelegate UAppLovinComponent::DidAppLovinfailedToReceiveAdDelegate;

UAppLovinComponent::FAppLovinadHiddenDelegate UAppLovinComponent::DidAppLovinadHiddenDelegate;


