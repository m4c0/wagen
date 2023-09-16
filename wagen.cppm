module;
#include "Vulkan-Headers/include/vulkan/vulkan_core.h"

export module wagen;

export namespace wagen {
using VkInstance = ::VkInstance;
using VkInstanceCreateInfo = ::VkInstanceCreateInfo;
using VkResult = ::VkResult;

PFN_vkCreateInstance vkCreateInstance;

void initialise() { vkCreateInstance = &::vkCreateInstance; }
} // namespace wagen
