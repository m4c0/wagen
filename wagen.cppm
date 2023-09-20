module;
#include "Vulkan-Headers/include/vulkan/vulkan_core.h"

export module wagen;

#if __APPLE__
export import :apple;
#elif _WIN32
export import :windows;
#endif

#ifdef __APPLE__
#define FN(x) PFN_##x x = &::x
#else
#define FN(x) PFN_##x x = [](auto... a) { return load(#x, x, a...); }
#endif
#define ST(x) using x = ::x

export namespace wagen {
constexpr const auto vk_api_version_1_0 = VK_API_VERSION_1_0;
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
ST(VkBufferCreateInfo);
ST(VkBufferImageCopy);
ST(VkClearColorValue);
ST(VkClearValue);
ST(VkCommandBuffer);
ST(VkCommandBufferAllocateInfo);
ST(VkCommandBufferBeginInfo);
ST(VkCommandBufferInheritanceInfo);
ST(VkCommandPool);
ST(VkCommandPoolCreateInfo);
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
ST(VkPhysicalDevice);
ST(VkPhysicalDeviceFeatures);
ST(VkPhysicalDeviceMemoryProperties);
ST(VkPhysicalDeviceProperties);
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
FN(vkGetImageMemoryRequirements);
FN(vkGetPhysicalDeviceFeatures);
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
