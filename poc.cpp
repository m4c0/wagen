#pragma leco app
import wagen;

int main() {
  using namespace wagen;

  wagen::initialise();

  VkInstance i{};
  VkInstanceCreateInfo info{
      .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
  };
  VkResult res = vkCreateInstance(&info, nullptr, &i);
  return res == VK_SUCCESS ? 0 : 1;
}
