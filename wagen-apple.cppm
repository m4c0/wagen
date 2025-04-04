module;
#include "Vulkan-Headers/include/vulkan/vulkan_core.h"
#include "Vulkan-Headers/include/vulkan/vulkan_metal.h"
#include <dlfcn.h>
#include <stdlib.h>

export module wagen:apple;
import silog;

static auto load_vulkan() {
#ifdef LECO_TARGET_MACOSX
  auto env = getenv("WAGEN_VULKAN_LOADER");
  if (env) {
    silog::log(silog::info, "Trying to use loader at [%s]", env);

    auto res = dlopen(env, RTLD_NOW | RTLD_LOCAL);
    if (res != nullptr) {
      silog::log(silog::info, "Using Vulkan dynamic loader defined via environment");
      return res;
    }
    silog::log(silog::debug, "Failed to load %s: %s", env, dlerror());
  }
  auto res = dlopen("libvulkan.dylib", RTLD_NOW | RTLD_LOCAL);
  if (res != nullptr) {
    silog::log(silog::info, "Using Vulkan dynamic loader");
    return res;
  }
  silog::log(silog::debug, "Failed to load libvulkan.dylib: %s", dlerror());

  res = dlopen("libMoltenVK.dylib", RTLD_NOW | RTLD_LOCAL);
  if (res != nullptr) {
    silog::log(silog::info, "Using MoltenVK dynamic library");
    return res;
  }
  silog::log(silog::debug, "Failed to load libMoltenVK.dylib: %s", dlerror());
#endif

  silog::log(silog::info, "Using static linked MoltenVK");
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

#ifdef LECO_TARGET_IOS
#pragma leco add_framework UIKit
#elif LECO_TARGET_MACOSX
#pragma leco add_framework AppKit
#endif

#if LECO_TARGET_MACOSX
#pragma leco add_dll "libvulkan.dylib"
#else
#pragma leco add_xcframework "MoltenVK.xcframework"
#endif

#ifdef LECO_TARGET_APPLE
#pragma leco add_framework CoreFoundation CoreGraphics Foundation IOKit
#pragma leco add_framework IOSurface MetalKit Metal QuartzCore
#endif
