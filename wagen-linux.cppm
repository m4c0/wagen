module;
#include <X11/Xlib.h>
#include <dlfcn.h>
#include <stdlib.h>

#include "Vulkan-Headers/include/vulkan/vulkan_core.h"
#include "Vulkan-Headers/include/vulkan/vulkan_xlib.h"

export module wagen:linux;
import silog;

static auto load_vulkan() {
  auto res = dlopen("libvulkan.so", RTLD_NOW | RTLD_LOCAL);
  if (res == nullptr) {
    silog::log(silog::error, "Failed to dlopen vulkan");
    exit(8);
  }
  silog::log(silog::info, "Using Vulkan dynamic loader");
  return res;
}
auto vulkan() {
  static auto h = load_vulkan();
  return h;
}

auto get_proc_address(const char *name) { return dlsym(vulkan(), name); }
void exit_process() { exit(9); }

export namespace wagen {
constexpr const auto vk_vulkan_platform_ext =
    VK_KHR_XLIB_SURFACE_EXTENSION_NAME;

using VkXlibSurfaceCreateInfoKHR = ::VkXlibSurfaceCreateInfoKHR;

using Display = ::Display;
using Window = ::Window;
} // namespace wagen
