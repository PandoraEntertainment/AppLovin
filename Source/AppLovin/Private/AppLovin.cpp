
#include "AppLovinPrivatePCH.h"
#include "AppLovinSettings.h"
#include "ISettingsModule.h"

DEFINE_LOG_CATEGORY(LogAppLovin);

#define LOCTEXT_NAMESPACE "AppLovin"

class FAppLovin : public IAppLovin
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FAppLovin, AppLovin )

void FAppLovin::StartupModule()
{
	// register settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "AppLovin",
										 LOCTEXT("RuntimeSettingsName", "AppLovin"),
										 LOCTEXT("RuntimeSettingsDescription", "Configure the AppLovin plugin"),
										 GetMutableDefault<UAppLovinSettings>()
										 );
	}

#if PLATFORM_ANDROID
	UAppLovinFunctions::InitJavaFunctions();
#endif
}


void FAppLovin::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
