#include "NativeSampleModule.h"

namespace facebook::react {

NativeSampleModule::NativeSampleModule(std::shared_ptr<CallInvoker> jsInvoker)
    : NativeSampleModuleCxxSpec(std::move(jsInvoker)) {}

std::string NativeSampleModule::reverseString(jsi::Runtime& rt, std::string input) {
  return std::string(input.rbegin(), input.rend());
}

std::int32_t NativeSampleModule::addNumbers(jsi::Runtime& rt, std::int32_t a, std::int32_t b) {
  return a + b;
}
} // namespace facebook::react