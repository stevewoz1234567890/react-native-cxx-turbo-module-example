/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// This C++ file is part of the default configuration used by apps and is placed
// inside react-native to encapsulate it from user space (so you won't need to
// touch C++/Cmake code at all on Android).
//
// If you wish to customize it (because you want to manually link a C++ library
// or pass a custom compilation flag) you can:
//
// 1. Copy this CMake file inside the `android/app/src/main/jni` folder of your
// project
// 2. Copy the OnLoad.cpp (in this same folder) file inside the same folder as
// above.
// 3. Extend your `android/app/build.gradle` as follows
//
// android {
//    // Other config here...
//    externalNativeBuild {
//        cmake {
//            path "src/main/jni/CMakeLists.txt"
//        }
//    }
// }

#include <DefaultComponentsRegistry.h>
#include <DefaultTurboModuleManagerDelegate.h>
#include <fbjni/fbjni.h>
#include <react/renderer/componentregistry/ComponentDescriptorProviderRegistry.h>
#include <rncli.h>
#include <NativeSampleModule.h> // Added include for NativeSampleModule

namespace facebook::react {

void registerComponents(
    std::shared_ptr<const ComponentDescriptorProviderRegistry> registry) {
  rncli_registerProviders(registry);
}

std::shared_ptr<TurboModule> cxxModuleProvider(
    const std::string& name,
    const std::shared_ptr<CallInvoker>& jsInvoker) {
  if (name == "NativeSampleModule") { // Check if the requested module is NativeSampleModule
    return std::make_shared<facebook::react::NativeSampleModule>(jsInvoker); // Create and return an instance of NativeSampleModule
  }
  return nullptr; // Return nullptr if no matching module is found
}

std::shared_ptr<TurboModule> javaModuleProvider(
    const std::string& name,
    const JavaTurboModule::InitParams& params) {
  return rncli_ModuleProvider(name, params);
}

} // namespace facebook::react

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void*) {
  return facebook::jni::initialize(vm, [] {
    facebook::react::DefaultTurboModuleManagerDelegate::cxxModuleProvider =
        &facebook::react::cxxModuleProvider;
    facebook::react::DefaultTurboModuleManagerDelegate::javaModuleProvider =
        &facebook::react::javaModuleProvider;
    facebook::react::DefaultComponentsRegistry::
        registerComponentDescriptorsFromEntryPoint =
            &facebook::react::registerComponents;
  });
}