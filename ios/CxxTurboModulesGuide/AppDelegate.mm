#import "AppDelegate.h"

#import <React/RCTBundleURLProvider.h>
#import <React/CoreModulesPlugins.h> // Added import
#import <ReactCommon/RCTTurboModuleManager.h> // Added import
#import <NativeSampleModule.h> // Added import

@interface AppDelegate () <RCTTurboModuleManagerDelegate> {} // Added interface
@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  self.moduleName = @"CxxTurboModulesGuide";
  self.initialProps = @{};

  return [super application:application didFinishLaunchingWithOptions:launchOptions];
}

- (NSURL *)sourceURLForBridge:(RCTBridge *)bridge
{
  return [self getBundleURL];
}

- (NSURL *)getBundleURL
{
#if DEBUG
  return [[RCTBundleURLProvider sharedSettings] jsBundleURLForBundleRoot:@"index"];
#else
  return [[NSBundle mainBundle] URLForResource:@"main" withExtension:@"jsbundle"];
#endif
}

// Added method
- (Class)getModuleClassFromName:(const char *)name
{
  return RCTCoreModulesClassProvider(name);
}

#pragma mark RCTTurboModuleManagerDelegate

// Added delegate method
- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:(const std::string &)name
                                                      jsInvoker:(std::shared_ptr<facebook::react::CallInvoker>)jsInvoker
{
  if (name == "NativeSampleModule") {
    return std::make_shared<facebook::react::NativeSampleModule>(jsInvoker);
  }
  return nullptr;
}

@end
