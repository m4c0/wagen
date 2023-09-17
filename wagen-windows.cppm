module;
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

export module wagen:windows;

HMODULE vulkan() {
  static HMODULE h = LoadLibraryA("vulkan-1");
  return h;
}

FARPROC load(const char *name) { return GetProcAddress(vulkan(), name); }
