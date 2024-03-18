module;
#include <dlfcn.h>
#include <stdlib.h>

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
