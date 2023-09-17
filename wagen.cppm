module;
#include "Vulkan-Headers/include/vulkan/vulkan_core.h"

export module wagen;

#ifdef _WIN32
import :windows;
#endif

#ifdef __APPLE__
#define FN(x) PFN_##x x = &::x;
#else
#define FN(x) PFN_##x x = reinterpret_cast<PFN_##x>(load(#x));
#endif

export namespace wagen {
using VkInstance = ::VkInstance;
using VkInstanceCreateInfo = ::VkInstanceCreateInfo;
using VkResult = ::VkResult;

FN(vkCreateInstance);
} // namespace wagen
