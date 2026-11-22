#include "vksetup.h"



void Core::vksetup::createCommandPool(VkContext& cxt)
{
    QueueFamilyIndices queueFamilyIndices = findQueueFamilies(cxt.physicalDevice, cxt);
    
    VkCommandPoolCreateInfo poolInfo{};
    poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    poolInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    poolInfo.queueFamilyIndex = queueFamilyIndices.graphicsFamily.value();

    if (vkCreateCommandPool(cxt.device, &poolInfo, nullptr, &cxt.commandPool) != VK_SUCCESS )
    {
        throw std::runtime_error("failed to create command pool!");
    }
}


void Core::vksetup::createCommandBuffer(VkContext& cxt)
{
    cxt.commandBuffers.resize(cxt.MAX_FRAMES_IN_FLIGHT);

    VkCommandBufferAllocateInfo allocInfo{};
    allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocInfo.commandPool = cxt.commandPool;
    allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocInfo.commandBufferCount = (uint32_t) cxt.commandBuffers.size();

    if (vkAllocateCommandBuffers(cxt.device, &allocInfo, cxt.commandBuffers.data()) != VK_SUCCESS) {
        throw std::runtime_error("failed to allocate command buffers!");
    }


}


void Core::vksetup::createSyncObjects(VkContext& cxt)
{
    cxt.imageAvailableSemaphores.resize(cxt.MAX_FRAMES_IN_FLIGHT);
    cxt.renderFinishedSemaphores.resize(cxt.MAX_FRAMES_IN_FLIGHT);
    cxt.inFlightFences.resize(cxt.MAX_FRAMES_IN_FLIGHT);

    VkSemaphoreCreateInfo semaphoreInfo{};
    semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

    VkFenceCreateInfo fenceInfo{};
    fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

    for (size_t i = 0; i < cxt.MAX_FRAMES_IN_FLIGHT; i++) {
        if (vkCreateSemaphore(cxt.device, &semaphoreInfo, nullptr, &cxt.imageAvailableSemaphores[i]) != VK_SUCCESS ||
            vkCreateSemaphore(cxt.device, &semaphoreInfo, nullptr, &cxt.renderFinishedSemaphores[i]) != VK_SUCCESS ||
            vkCreateFence(cxt.device, &fenceInfo, nullptr, &cxt.inFlightFences[i]) != VK_SUCCESS) {
            throw std::runtime_error("failed to create synchronization objects for a frame!");
        }
    }

}


