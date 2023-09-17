module;
#include "Vulkan-Headers/include/vulkan/vulkan_core.h"

export module wagen;

#ifdef _WIN32
import :windows;
#endif

export namespace wagen {
using VkInstance = ::VkInstance;
using VkInstanceCreateInfo = ::VkInstanceCreateInfo;
using VkResult = ::VkResult;

#ifdef __APPLE__
PFN_vkCreateInstance vkCreateInstance = &::vkCreateInstance;
#else
PFN_vkCreateInstance vkCreateInstance =
    reinterpret_cast<PFN_vkCreateInstance>(load("vkCreateInstance"));
#endif
} // namespace wagen

#ifdef LECO_TARGET_IPHONEOS
#define MOLTEN "MoltenVK.xcframework/ios-arm64/libMoltenVK.a"
#pragma leco add_framework UIKit
#elif LECO_TARGET_IPHONESIMULATOR
#define MOLTEN "MoltenVK.xcframework/ios-arm64_x86_64-simulator/libMoltenVK.a"
#pragma leco add_framework UIKit
#elif LECO_TARGET_MACOSX
#define MOLTEN "MoltenVK.xcframework/macos-arm64_x86_64/libMoltenVK.a"
#pragma leco add_framework AppKit
#endif

#ifdef LECO_TARGET_APPLE
#pragma leco add_object MOLTEN
#pragma leco add_framework CoreFoundation CoreGraphics Foundation IOKit        \
    IOSurface MetalKit Metal QuartzCore
#endif
