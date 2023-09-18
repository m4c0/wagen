module;
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "Vulkan-Headers/include/vulkan/vulkan_core.h"
#include "Vulkan-Headers/include/vulkan/vulkan_win32.h"

export module wagen:windows;

HMODULE vulkan() {
  static HMODULE h = LoadLibraryA("vulkan-1");
  return h;
}

FARPROC load(const char *name) { return GetProcAddress(vulkan(), name); }

export namespace wagen {
constexpr const auto vk_vulkan_platform_ext =
    VK_KHR_WIN32_SURFACE_EXTENSION_NAME;

using HWND = ::HWND;
using VkWin32SurfaceCreateInfoKHR = ::VkWin32SurfaceCreateInfoKHR;

PFN_vkCreateWin32SurfaceKHR vkCreateWin32SurfaceKHR =
    reinterpret_cast<PFN_vkCreateWin32SurfaceKHR>(
        load("vkCreateWin32SurfaceKHR"));

auto get_module_handle = &::GetModuleHandle;
} // namespace wagen
