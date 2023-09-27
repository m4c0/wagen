module;
#include "Vulkan-Headers/include/vulkan/vulkan_core.h"
#include "Vulkan-Headers/include/vulkan/vulkan_metal.h"
#include <dlfcn.h>
#include <stdlib.h>

export module wagen:apple;
import silog;

static auto load_vulkan() {
  auto res = dlopen("libvulkan.dylib", RTLD_NOW | RTLD_LOCAL);
  if (res != nullptr) {
    silog::log(silog::info, "Using Vulkan dynamic loader");
    return res;
  }
  return dlopen(nullptr, RTLD_LAZY);
}
auto vulkan() {
  static auto h = load_vulkan();
  return h;
}

auto get_proc_address(const char *name) { return dlsym(vulkan(), name); }
void exit_process() { exit(9); }

export namespace wagen {
using CAMetalLayer = ::CAMetalLayer;
using VkMetalSurfaceCreateInfoEXT = ::VkMetalSurfaceCreateInfoEXT;

constexpr const auto vk_vulkan_platform_ext =
    VK_EXT_METAL_SURFACE_EXTENSION_NAME;
constexpr const auto vk_khr_portability_enumeration_extension_name =
    VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME;
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
