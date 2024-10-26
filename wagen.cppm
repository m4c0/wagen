module;
#include "Vulkan-Headers/include/vulkan/vulkan_core.h"

#if __APPLE__
#include "Vulkan-Headers/include/vulkan/vulkan_metal.h"
#elif _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "Vulkan-Headers/include/vulkan/vulkan_win32.h"
#elif __linux__
#include <X11/Xlib.h>
#include "Vulkan-Headers/include/vulkan/vulkan_xlib.h"
#endif

export module wagen;
import silog;

#if LECO_TARGET_APPLE
export import :apple;
#elif LECO_TARGET_WINDOWS
export import :windows;
#elif LECO_TARGET_LINUX
export import :linux;
#else
#error unsupported platform
#endif

#define FN(x) PFN_##x x = [](auto... a) { return load(#x, x, a...); }
#define ST(x) using x = ::x

export namespace wagen {
VkDevice &device();
VkInstance &instance();
} // namespace wagen

template <typename T> static auto load_proc_addr(const char *name) {
  auto res = reinterpret_cast<T>(get_proc_address(name));
  if (!res) {
    silog::log(silog::error, "Proc loader [%s] not found in Vulkan", name);
    exit_process();
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
    exit_process();
  }
  return fn(args...);
}
template <typename PFN>
auto load(const char *name, PFN &fn, VkInstance i, auto... args) {
  fn = reinterpret_cast<PFN>(get_instance_proc_addr(i, name));
  if (!fn) {
    silog::log(silog::error, "Instance proc [%s] not found in Vulkan", name);
    exit_process();
  }
  return fn(i, args...);
}
template <typename PFN>
auto load(const char *name, PFN &fn, VkDevice d, auto... args) {
  fn = reinterpret_cast<PFN>(get_device_proc_addr(d, name));
  if (!fn) {
    silog::log(silog::error, "Device proc [%s] not found in Vulkan", name);
    exit_process();
  }
  return fn(d, args...);
}

export namespace wagen {
constexpr const auto vk_api_version_1_0 = VK_API_VERSION_1_0;
constexpr const auto vk_api_version_1_1 = VK_API_VERSION_1_1;
constexpr const auto vk_ext_debug_utils_extension_name =
    VK_EXT_DEBUG_UTILS_EXTENSION_NAME;
constexpr const auto vk_false = VK_FALSE;
constexpr const auto vk_khr_surface_extension_name =
    VK_KHR_SURFACE_EXTENSION_NAME;
constexpr const auto vk_khr_swapchain_extension_name =
    VK_KHR_SWAPCHAIN_EXTENSION_NAME;
constexpr const auto vk_null_handle = VK_NULL_HANDLE;
constexpr const auto vk_queue_family_ignored = VK_QUEUE_FAMILY_IGNORED;
constexpr const auto vk_subpass_external = VK_SUBPASS_EXTERNAL;
constexpr const auto vk_true = VK_TRUE;
constexpr const auto vk_whole_size = VK_WHOLE_SIZE;

ST(VkApplicationInfo);
ST(VkAttachmentDescription);
ST(VkAttachmentReference);
ST(VkBool32);
ST(VkBuffer);
ST(VkBufferCopy);
ST(VkBufferCreateInfo);
ST(VkBufferImageCopy);
ST(VkBufferMemoryBarrier);
ST(VkClearColorValue);
ST(VkClearValue);
ST(VkCommandBuffer);
ST(VkCommandBufferAllocateInfo);
ST(VkCommandBufferBeginInfo);
ST(VkCommandBufferInheritanceInfo);
ST(VkCommandPool);
ST(VkCommandPoolCreateInfo);
ST(VkComponentMapping);
ST(VkDebugUtilsMessageSeverityFlagBitsEXT);
ST(VkDebugUtilsMessageTypeFlagsEXT);
ST(VkDebugUtilsMessengerCallbackDataEXT);
ST(VkDebugUtilsMessengerCreateInfoEXT);
ST(VkDebugUtilsMessengerEXT);
ST(VkDescriptorBufferInfo);
ST(VkDescriptorImageInfo);
ST(VkDescriptorPool);
ST(VkDescriptorPoolCreateInfo);
ST(VkDescriptorPoolSize);
ST(VkDescriptorSet);
ST(VkDescriptorSetAllocateInfo);
ST(VkDescriptorSetLayout);
ST(VkDescriptorSetLayoutBinding);
ST(VkDescriptorSetLayoutCreateInfo);
ST(VkDevice);
ST(VkDeviceCreateInfo);
ST(VkDeviceMemory);
ST(VkDeviceQueueCreateInfo);
ST(VkDeviceSize);
ST(VkDynamicState);
ST(VkExtensionProperties);
ST(VkExtent2D);
ST(VkFence);
ST(VkFenceCreateInfo);
ST(VkFormat);
ST(VkFormatProperties);
ST(VkFramebuffer);
ST(VkFramebufferCreateInfo);
ST(VkGraphicsPipelineCreateInfo);
ST(VkImage);
ST(VkImageAspectFlags);
ST(VkImageCreateInfo);
ST(VkImageLayout);
ST(VkImageMemoryBarrier);
ST(VkImageView);
ST(VkImageViewCreateInfo);
ST(VkInstance);
ST(VkInstanceCreateInfo);
ST(VkLayerProperties);
ST(VkMemoryAllocateFlags);
ST(VkMemoryAllocateInfo);
ST(VkMemoryRequirements);
ST(VkOffset2D);
ST(VkPhysicalDevice);
ST(VkPhysicalDeviceFeatures);
ST(VkPhysicalDeviceMemoryProperties);
ST(VkPhysicalDeviceProperties);
ST(VkPhysicalDeviceSamplerYcbcrConversionFeatures);
ST(VkPipeline);
ST(VkPipelineColorBlendAttachmentState);
ST(VkPipelineColorBlendStateCreateInfo);
ST(VkPipelineDepthStencilStateCreateInfo);
ST(VkPipelineDynamicStateCreateInfo);
ST(VkPipelineInputAssemblyStateCreateInfo);
ST(VkPipelineLayout);
ST(VkPipelineLayoutCreateInfo);
ST(VkPipelineMultisampleStateCreateInfo);
ST(VkPipelineRasterizationStateCreateInfo);
ST(VkPipelineShaderStageCreateInfo);
ST(VkPipelineStageFlags);
ST(VkPipelineVertexInputStateCreateInfo);
ST(VkPipelineViewportStateCreateInfo);
ST(VkPresentInfoKHR);
ST(VkPresentModeKHR);
ST(VkPrimitiveTopology);
ST(VkPushConstantRange);
ST(VkQueue);
ST(VkQueueFamilyProperties);
ST(VkRect2D);
ST(VkRenderPass);
ST(VkRenderPassBeginInfo);
ST(VkRenderPassCreateInfo);
ST(VkResult);
ST(VkSampler);
ST(VkSamplerCreateInfo);
ST(VkSamplerYcbcrConversion);
ST(VkSamplerYcbcrConversionInfo);
ST(VkSamplerYcbcrConversionCreateInfo);
ST(VkSemaphore);
ST(VkSemaphoreCreateInfo);
ST(VkShaderModule);
ST(VkShaderModuleCreateInfo);
ST(VkSubmitInfo);
ST(VkSubpassContents);
ST(VkSubpassDependency);
ST(VkSubpassDescription);
ST(VkSurfaceCapabilitiesKHR);
ST(VkSurfaceFormatKHR);
ST(VkSurfaceKHR);
ST(VkSwapchainCreateInfoKHR);
ST(VkSwapchainKHR);
ST(VkVertexInputAttributeDescription);
ST(VkVertexInputBindingDescription);
ST(VkViewport);
ST(VkWriteDescriptorSet);

FN(vkAcquireNextImageKHR);
FN(vkAllocateCommandBuffers);
FN(vkAllocateDescriptorSets);
FN(vkAllocateMemory);
FN(vkBeginCommandBuffer);
FN(vkBindBufferMemory);
FN(vkBindImageMemory);
FN(vkCmdBeginRenderPass);
FN(vkCmdBindDescriptorSets);
FN(vkCmdBindPipeline);
FN(vkCmdBindVertexBuffers);
FN(vkCmdCopyBuffer);
FN(vkCmdCopyBufferToImage);
FN(vkCmdCopyImageToBuffer);
FN(vkCmdDraw);
FN(vkCmdEndRenderPass);
FN(vkCmdExecuteCommands);
FN(vkCmdPipelineBarrier);
FN(vkCmdPushConstants);
FN(vkCmdSetScissor);
FN(vkCmdSetViewport);
FN(vkCreateBuffer);
FN(vkCreateCommandPool);
FN(vkCreateDebugUtilsMessengerEXT);
FN(vkCreateDescriptorPool);
FN(vkCreateDescriptorSetLayout);
FN(vkCreateDevice);
FN(vkCreateFence);
FN(vkCreateFramebuffer);
FN(vkCreateGraphicsPipelines);
FN(vkCreateImage);
FN(vkCreateImageView);
FN(vkCreateInstance);
FN(vkCreatePipelineLayout);
FN(vkCreateRenderPass);
FN(vkCreateSampler);
FN(vkCreateSamplerYcbcrConversion);
FN(vkCreateSemaphore);
FN(vkCreateShaderModule);
FN(vkCreateSwapchainKHR);
FN(vkDestroyBuffer);
FN(vkDestroyCommandPool);
FN(vkDestroyDebugUtilsMessengerEXT);
FN(vkDestroyDescriptorPool);
FN(vkDestroyDescriptorSetLayout);
FN(vkDestroyDevice);
FN(vkDestroyFence);
FN(vkDestroyFramebuffer);
FN(vkDestroyImage);
FN(vkDestroyImageView);
FN(vkDestroyInstance);
FN(vkDestroyPipeline);
FN(vkDestroyPipelineLayout);
FN(vkDestroyRenderPass);
FN(vkDestroySampler);
FN(vkDestroySamplerYcbcrConversion);
FN(vkDestroySemaphore);
FN(vkDestroyShaderModule);
FN(vkDestroySurfaceKHR);
FN(vkDestroySwapchainKHR);
FN(vkDeviceWaitIdle);
FN(vkEndCommandBuffer);
FN(vkEnumerateInstanceExtensionProperties);
FN(vkEnumerateInstanceLayerProperties);
FN(vkEnumeratePhysicalDevices);
FN(vkFreeMemory);
FN(vkGetBufferMemoryRequirements);
FN(vkGetDeviceQueue);
FN(vkGetFenceStatus);
FN(vkGetImageMemoryRequirements);
FN(vkGetPhysicalDeviceFeatures);
FN(vkGetPhysicalDeviceFormatProperties);
FN(vkGetPhysicalDeviceMemoryProperties);
FN(vkGetPhysicalDeviceProperties);
FN(vkGetPhysicalDeviceQueueFamilyProperties);
FN(vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
FN(vkGetPhysicalDeviceSurfaceFormatsKHR);
FN(vkGetPhysicalDeviceSurfacePresentModesKHR);
FN(vkGetPhysicalDeviceSurfaceSupportKHR);
FN(vkGetSwapchainImagesKHR);
FN(vkMapMemory);
FN(vkQueuePresentKHR);
FN(vkQueueSubmit);
FN(vkResetFences);
FN(vkUnmapMemory);
FN(vkUpdateDescriptorSets);
FN(vkWaitForFences);

#if __APPLE__
FN(vkCreateMetalSurfaceEXT);
#elif _WIN32
FN(vkCreateWin32SurfaceKHR);
#elif __linux__
FN(vkCreateXlibSurfaceKHR);
#endif

template <auto *Fn, typename... Args>
VKAPI_ATTR auto VKAPI_CALL callback(Args... in) {
  return Fn(in...);
}
} // namespace wagen

module :private;

VkDevice g_device{};
VkDevice &wagen::device() { return g_device; }

VkInstance g_instance{};
VkInstance &wagen::instance() { return g_instance; }
