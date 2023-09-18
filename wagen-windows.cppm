module;
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "Vulkan-Headers/include/vulkan/vulkan_core.h"
#include "Vulkan-Headers/include/vulkan/vulkan_win32.h"

export module wagen:windows;
import silog;

export namespace wagen {
VkInstance &instance();
}

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

template <typename T> static auto load_proc_addr(const char *name) {
  auto res = reinterpret_cast<T>(GetProcAddress(vulkan(), name));
  if (!res) {
    silog::log(silog::error, "Proc loader [%s] not found in Vulkan", name);
    ExitProcess(9);
  }
  return res;
}
auto get_instance_proc_addr(VkInstance ctx, const char *name) {
  static auto res =
      load_proc_addr<PFN_vkGetInstanceProcAddr>("vkGetInstanceProcAddr");
  return res(ctx, name);
}
auto get_device_proc_addr(VkDevice ctx, const char *name) {
  static auto res =
      load_proc_addr<PFN_vkGetDeviceProcAddr>("vkGetDeviceProcAddr");
  return res(ctx, name);
}

template <typename PFN> auto load(const char *name, PFN &fn, auto... args) {
  fn = reinterpret_cast<PFN>(get_instance_proc_addr(wagen::instance(), name));
  if (!fn) {
    silog::log(silog::error, "Base proc [%s] not found in Vulkan", name);
    ExitProcess(9);
  }
  return fn(args...);
}
template <typename PFN>
auto load(const char *name, PFN &fn, VkInstance i, auto... args) {
  fn = reinterpret_cast<PFN>(get_instance_proc_addr(i, name));
  if (!fn) {
    silog::log(silog::error, "Instance proc [%s] not found in Vulkan", name);
    ExitProcess(9);
  }
  return fn(i, args...);
}
template <typename PFN>
auto load(const char *name, PFN &fn, VkDevice d, auto... args) {
  fn = reinterpret_cast<PFN>(get_device_proc_addr(d, name));
  if (!fn) {
    silog::log(silog::error, "Device proc [%s] not found in Vulkan", name);
    ExitProcess(9);
  }
  return fn(d, args...);
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
