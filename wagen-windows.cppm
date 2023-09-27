module;
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "Vulkan-Headers/include/vulkan/vulkan_core.h"
#include "Vulkan-Headers/include/vulkan/vulkan_win32.h"

export module wagen:windows;
import silog;

static HMODULE load_vulkan() {
  auto res = LoadLibraryA("vulkan-1");
  if (!res) {
    silog::log(silog::error, "VULKAN-1.DLL not found");
    ExitProcess(9);
  }
  return res;
}
HMODULE vulkan() {
  static HMODULE h = load_vulkan();
  return h;
}

auto get_proc_address(const char *name) {
  return GetProcAddress(vulkan(), name);
}
void exit_process() { ExitProcess(9); }

export namespace wagen {
constexpr const auto vk_vulkan_platform_ext =
    VK_KHR_WIN32_SURFACE_EXTENSION_NAME;

using HWND = ::HWND;
using VkWin32SurfaceCreateInfoKHR = ::VkWin32SurfaceCreateInfoKHR;

auto get_module_handle = &::GetModuleHandle;
} // namespace wagen
