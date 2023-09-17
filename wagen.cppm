module;
#include "Vulkan-Headers/include/vulkan/vulkan_core.h"

export module wagen;

#ifdef _WIN32
import :windows;
#endif

#ifdef __APPLE__
#define FN(x) PFN_##x x = &::x
#else
#define FN(x) PFN_##x x = reinterpret_cast<PFN_##x>(load(#x))
#endif
#define ST(x) using x = ::x

export namespace wagen {
constexpr const auto vk_vulkan_platform_ext = "BLAH";

constexpr const auto vk_api_version_1_0 = VK_API_VERSION_1_0;
constexpr const auto vk_false = VK_FALSE;
constexpr const auto vk_ext_debug_utils_extension_name =
    VK_EXT_DEBUG_UTILS_EXTENSION_NAME;
constexpr const auto vk_khr_surface_extension_name =
    VK_KHR_SURFACE_EXTENSION_NAME;
constexpr const auto vk_null_handle = VK_NULL_HANDLE;
constexpr const auto vk_whole_size = VK_WHOLE_SIZE;

ST(VkApplicationInfo);
ST(VkBool32);
ST(VkBuffer);
ST(VkDebugUtilsMessageSeverityFlagBitsEXT);
ST(VkDebugUtilsMessageTypeFlagsEXT);
ST(VkDebugUtilsMessengerCallbackDataEXT);
ST(VkDebugUtilsMessengerCreateInfoEXT);
ST(VkDebugUtilsMessengerEXT);
ST(VkDevice);
ST(VkDeviceMemory);
ST(VkDeviceSize);
ST(VkExtensionProperties);
ST(VkImage);
ST(VkInstance);
ST(VkInstanceCreateInfo);
ST(VkLayerProperties);
ST(VkResult);
ST(VkSemaphore);
ST(VkSwapchainKHR);

FN(vkAcquireNextImageKHR);
FN(vkBindBufferMemory);
FN(vkBindImageMemory);
FN(vkCreateDebugUtilsMessengerEXT);
FN(vkCreateInstance);
FN(vkDestroyDebugUtilsMessengerEXT);
FN(vkDestroyInstance);
FN(vkDeviceWaitIdle);
FN(vkEnumerateInstanceExtensionProperties);
FN(vkEnumerateInstanceLayerProperties);
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

template <auto *Fn, typename... Args>
VKAPI_ATTR auto VKAPI_CALL callback(Args... in) {
  return Fn(in...);
}
} // namespace wagen
