module;
#include "Vulkan-Headers/include/vulkan/vulkan_core.h"
#include "Vulkan-Headers/include/vulkan/vulkan_metal.h"
#include <dlfcn.h>
#include <stdlib.h>

export module wagen:apple;

auto vulkan() {
  static auto h = dlopen(nullptr, RTLD_LAZY);
  return h;
}

auto get_proc_address(const char *name) { return dlsym(vulkan(), name); }
void exit_process() { exit(9); }

export namespace wagen {
using CAMetalLayer = ::CAMetalLayer;
using VkMetalSurfaceCreateInfoEXT = ::VkMetalSurfaceCreateInfoEXT;

constexpr const auto vk_vulkan_platform_ext =
    VK_EXT_METAL_SURFACE_EXTENSION_NAME;

PFN_vkCreateMetalSurfaceEXT vkCreateMetalSurfaceEXT =
    &::vkCreateMetalSurfaceEXT;
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
