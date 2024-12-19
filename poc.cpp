#pragma leco app
import silog;
import wagen;

int main() {
  using namespace wagen;

  VkInstance i{};
  VkInstanceCreateInfo info{
      .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
  };
  VkResult res = vkCreateInstance(&info, nullptr, &i);
  silog::log(silog::info, "vkCreateInstance returned %d", res);
  return res == VK_SUCCESS ? 0 : 1;
}
