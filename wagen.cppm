module;
#include "Vulkan-Headers/include/vulkan/vulkan_core.h"

export module wagen;

#if __APPLE__
import :apple;
#elif _WIN32
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
constexpr const auto vk_ext_debug_utils_extension_name =
    VK_EXT_DEBUG_UTILS_EXTENSION_NAME;
constexpr const auto vk_false = VK_FALSE;
constexpr const auto vk_khr_surface_extension_name =
    VK_KHR_SURFACE_EXTENSION_NAME;
constexpr const auto vk_null_handle = VK_NULL_HANDLE;
constexpr const auto vk_queue_family_ignored = VK_QUEUE_FAMILY_IGNORED;
constexpr const auto vk_true = VK_TRUE;
constexpr const auto vk_whole_size = VK_WHOLE_SIZE;

ST(VkApplicationInfo);
ST(VkBool32);
ST(VkBuffer);
ST(VkBuffer);
ST(VkBufferCreateInfo);
ST(VkBufferImageCopy);
ST(VkClearColorValue);
ST(VkClearValue);
ST(VkCommandBuffer);
ST(VkCommandBufferAllocateInfo);
ST(VkCommandBufferBeginInfo);
ST(VkCommandBufferBeginInfo);
ST(VkCommandBufferInheritanceInfo);
ST(VkCommandPool);
ST(VkDebugUtilsMessageSeverityFlagBitsEXT);
ST(VkDebugUtilsMessageTypeFlagsEXT);
ST(VkDebugUtilsMessengerCallbackDataEXT);
ST(VkDebugUtilsMessengerCreateInfoEXT);
ST(VkDebugUtilsMessengerEXT);
ST(VkDescriptorBufferInfo);
ST(VkDescriptorImageInfo);
ST(VkDescriptorPool);
ST(VkDescriptorSet);
ST(VkDescriptorSetAllocateInfo);
ST(VkDescriptorSetLayout);
ST(VkDevice);
ST(VkDeviceMemory);
ST(VkDeviceSize);
ST(VkExtensionProperties);
ST(VkExtent2D);
ST(VkFence);
ST(VkFramebuffer);
ST(VkImage);
ST(VkImageMemoryBarrier);
ST(VkImageView);
ST(VkInstance);
ST(VkInstanceCreateInfo);
ST(VkLayerProperties);
ST(VkPhysicalDevice);
ST(VkPipeline);
ST(VkPipelineLayout);
ST(VkPipelineStageFlags);
ST(VkPresentInfoKHR);
ST(VkQueue);
ST(VkRect2D);
ST(VkRenderPass);
ST(VkRenderPassBeginInfo);
ST(VkResult);
ST(VkSampler);
ST(VkSemaphore);
ST(VkSubmitInfo);
ST(VkSubpassContents);
ST(VkSwapchainKHR);
ST(VkViewport);
ST(VkWriteDescriptorSet);
ST(VkWriteDescriptorSet);

FN(vkAcquireNextImageKHR);
FN(vkAllocateCommandBuffers);
FN(vkAllocateDescriptorSets);
FN(vkBeginCommandBuffer);
FN(vkBindBufferMemory);
FN(vkBindImageMemory);
FN(vkCmdBeginRenderPass);
FN(vkCmdBindDescriptorSets);
FN(vkCmdBindPipeline);
FN(vkCmdBindVertexBuffers);
FN(vkCmdCopyBufferToImage);
FN(vkCmdDraw);
FN(vkCmdEndRenderPass);
FN(vkCmdExecuteCommands);
FN(vkCmdPipelineBarrier);
FN(vkCmdPushConstants);
FN(vkCmdSetScissor);
FN(vkCmdSetViewport);
FN(vkCreateBuffer);
FN(vkCreateDebugUtilsMessengerEXT);
FN(vkCreateInstance);
FN(vkDestroyBuffer);
FN(vkDestroyDebugUtilsMessengerEXT);
FN(vkDestroyInstance);
FN(vkDeviceWaitIdle);
FN(vkEndCommandBuffer);
FN(vkEnumerateInstanceExtensionProperties);
FN(vkEnumerateInstanceLayerProperties);
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
