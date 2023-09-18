module;
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "Vulkan-Headers/include/vulkan/vulkan_core.h"
#include "Vulkan-Headers/include/vulkan/vulkan_win32.h"

export module wagen:windows;
import silog;

HMODULE vulkan() {
  static HMODULE h = [] {
    auto res = LoadLibraryA("vulkan-1");
    if (!res) {
      silog::log(silog::error, "VULKAN-1.DLL not found");
      ExitProcess(9);
    }
    return res;
  }();
  return h;
}

template <typename PFN> auto load(const char *name, PFN &fn, auto... args) {
  static const auto l = [] {
    auto res = reinterpret_cast<PFN_vkGetInstanceProcAddr>(
        GetProcAddress(vulkan(), "vkGetInstanceProcAddr"));
    if (!res) {
      silog::log(silog::error, "vkGetInstanceProcAddr not found in Vulkan");
      ExitProcess(9);
    }
    return res;
  }();

  fn = reinterpret_cast<PFN>(l(nullptr, name));
  if (!fn) {
    silog::log(silog::error, "Failed to find [%s] in Vulkan", name);
    ExitProcess(9);
  }
  return fn(args...);
}

export namespace wagen {
constexpr const auto vk_vulkan_platform_ext =
    VK_KHR_WIN32_SURFACE_EXTENSION_NAME;

using HWND = ::HWND;
using VkWin32SurfaceCreateInfoKHR = ::VkWin32SurfaceCreateInfoKHR;

PFN_vkCreateWin32SurfaceKHR vkCreateWin32SurfaceKHR = [](auto... a) {
  return load("vkCreateWin32SurfaceKHR", vkCreateWin32SurfaceKHR, a...);
};

auto get_module_handle = &::GetModuleHandle;
} // namespace wagen
