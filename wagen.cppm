module;
#include "Vulkan-Headers/include/vulkan/vulkan_core.h"

export module wagen;

#ifdef _WIN32
import :windows;
#endif

export namespace wagen {
using VkInstance = ::VkInstance;
using VkInstanceCreateInfo = ::VkInstanceCreateInfo;
using VkResult = ::VkResult;

#ifdef __APPLE__
PFN_vkCreateInstance vkCreateInstance = &::vkCreateInstance;
#else
PFN_vkCreateInstance vkCreateInstance =
    reinterpret_cast<PFN_vkCreateInstance>(load("vkCreateInstance"));
#endif
} // namespace wagen
