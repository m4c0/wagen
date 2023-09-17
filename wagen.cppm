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
constexpr const auto vk_vulkan_platform_ext = "BLAH";

constexpr const auto vk_api_version_1_0 = VK_API_VERSION_1_0;
constexpr const auto vk_ext_debug_utils_extension_name =
    VK_EXT_DEBUG_UTILS_EXTENSION_NAME;
constexpr const auto vk_khr_surface_extension_name =
    VK_KHR_SURFACE_EXTENSION_NAME;
constexpr const auto vk_null_handle = VK_NULL_HANDLE;
constexpr const auto vk_whole_size = VK_WHOLE_SIZE;

using VkApplicationInfo = ::VkApplicationInfo;
using VkBuffer = ::VkBuffer;
using VkDevice = ::VkDevice;
using VkDeviceMemory = ::VkDeviceMemory;
using VkDeviceSize = ::VkDeviceSize;
using VkImage = ::VkImage;
using VkInstance = ::VkInstance;
using VkInstanceCreateInfo = ::VkInstanceCreateInfo;
using VkLayerProperties = ::VkLayerProperties;
using VkExtensionProperties = ::VkExtensionProperties;
using VkResult = ::VkResult;
using VkSemaphore = ::VkSemaphore;
using VkSwapchainKHR = ::VkSwapchainKHR;

FN(vkAcquireNextImageKHR);
FN(vkBindBufferMemory);
FN(vkBindImageMemory);
FN(vkCreateInstance);
FN(vkDestroyInstance);
FN(vkDeviceWaitIdle);
FN(vkEnumerateInstanceLayerProperties);
FN(vkEnumerateInstanceExtensionProperties);
FN(vkMapMemory);
FN(vkUnmapMemory);

VkDevice &device() {
  static VkDevice i{};
  return i;
}
VkInstance &instance() {
  static VkInstance i{};
  return i;
}
} // namespace wagen
