
#include "AppLovinPrivatePCH.h"

#if PLATFORM_ANDROID

#include "Android/AndroidJNI.h"
#include "AndroidApplication.h"

#define INIT_JAVA_METHOD(name, signature) \
if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true)) { \
	name = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, #name, signature, false); \
	check(name != NULL); \
} else { \
	check(0); \
}

#define DECLARE_JAVA_METHOD(name) \
static jmethodID name = NULL;

DECLARE_JAVA_METHOD(AndroidThunkJava_AppLovin_HasRewardedVideo);
DECLARE_JAVA_METHOD(AndroidThunkJava_AppLovin_ShowRewardedVideo);
DECLARE_JAVA_METHOD(AndroidThunkJava_AppLovin_PreloadRewardedVideo);

void UAppLovinFunctions::InitJavaFunctions()
{
	//INIT_JAVA_METHOD(AndroidThunkJava_AppLovin_HasRewardedVideo, "(Ljava/lang/String;)Z");
	INIT_JAVA_METHOD(AndroidThunkJava_AppLovin_HasRewardedVideo, "()Z");
	//INIT_JAVA_METHOD(AndroidThunkJava_AppLovin_ShowRewardedVideo, "(Ljava/lang/String;)V");
	INIT_JAVA_METHOD(AndroidThunkJava_AppLovin_ShowRewardedVideo, "()V");
	//INIT_JAVA_METHOD(AndroidThunkJava_AppLovin_PreloadRewardedVideo, "(Ljava/lang/String;)V");
	INIT_JAVA_METHOD(AndroidThunkJava_AppLovin_PreloadRewardedVideo, "()V");
}
#undef DECLARE_JAVA_METHOD
#undef INIT_JAVA_METHOD


// This function is declared in the Java - defined class, GameActivity.java : "public native void nativeAppLovinadReceived();"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeAppLovinadReceived(JNIEnv* jenv, jobject thiz)
{


	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		UAppLovinComponent::DidAppLovinadReceivedDelegate.Broadcast();
	}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
		);
}


// This function is declared in the Java - defined class, GameActivity.java : "public native void nativeAppLovinfailedToReceiveAd();"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeAppLovinfailedToReceiveAd(JNIEnv* jenv, jobject thiz)
{


	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		UAppLovinComponent::DidAppLovinfailedToReceiveAdDelegate.Broadcast();
	}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
		);
}


// This function is declared in the Java - defined class, GameActivity.java : "public native void nativeAppLovinadHidden();"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeAppLovinadHidden(JNIEnv* jenv, jobject thiz)
{


	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		UAppLovinComponent::DidAppLovinadHiddenDelegate.Broadcast();
	}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
		);
}



// This function is declared in the Java - defined class, GameActivity.java : "public native void nativeAppLovinuserRewardVerified();"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeAppLovinuserRewardVerified(JNIEnv* jenv, jobject thiz)
{


	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		UAppLovinComponent::DidAppLovinCompleteRewardedVideoDelegate.Broadcast();
	}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
		);
}


#endif





void UAppLovinFunctions::AppLovinShowRewardedVideo() {

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_AppLovin_ShowRewardedVideo);

		

		UE_LOG(LogAndroid, Warning, TEXT("I found the java method ApplovinShowRewardedVideo\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif
}




bool UAppLovinFunctions::AppLovinHasRewardedVideo() {

#if PLATFORM_IOS

#elif PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		

		bool ret = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_AppLovin_HasRewardedVideo);

		

		UE_LOG(LogAndroid, Warning, TEXT("I found the java method ApplovinHasRewardedVide\n"));

		return ret;
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif

	return false;
}



void UAppLovinFunctions::AppLovinPreloadRewardedVideo() {

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{


		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_AppLovin_PreloadRewardedVideo);



		UE_LOG(LogAndroid, Warning, TEXT("I found the java method AndroidThunkJava_AppLovin_PreloadRewardedVideo\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif
}
