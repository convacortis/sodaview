#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "renderer.h"



Graphics::Renderer::Renderer(Core::vksetup::VkContext& cxt) : m_cxt(cxt) {}



void Graphics::Renderer::recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex)
{
    VkCommandBufferBeginInfo beginInfo{};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

    if (vkBeginCommandBuffer(commandBuffer, &beginInfo) != VK_SUCCESS) {
        throw std::runtime_error("failed to begin recording command buffer!");
    }

    VkRenderPassBeginInfo renderPassInfo{};
    renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    renderPassInfo.renderPass = m_cxt.renderPass;
    renderPassInfo.framebuffer = m_cxt.swapChainFramebuffers[imageIndex];
    renderPassInfo.renderArea.offset = {0, 0};
    renderPassInfo.renderArea.extent = m_cxt.swapChainExtent;

    VkClearValue clearColor = {{{0.0f, 0.0f, 0.0f, 1.0f}}};
    renderPassInfo.clearValueCount = 1;
    renderPassInfo.pClearValues = &clearColor;

    vkCmdBeginRenderPass(commandBuffer, &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);

        vkCmdBindPipeline(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, m_cxt.graphicsPipeline);

        VkViewport viewport{};
        viewport.x = 0.0f;
        viewport.y = 0.0f;
        viewport.width = (float) m_cxt.swapChainExtent.width;
        viewport.height = (float) m_cxt.swapChainExtent.height;
        viewport.minDepth = 0.0f;
        viewport.maxDepth = 1.0f;
        vkCmdSetViewport(commandBuffer, 0, 1, &viewport);

        VkRect2D scissor{};
        scissor.offset = {0, 0};
        scissor.extent = m_cxt.swapChainExtent;
        vkCmdSetScissor(commandBuffer, 0, 1, &scissor);

        vkCmdDraw(commandBuffer, 3, 1, 0, 0);

    vkCmdEndRenderPass(commandBuffer);

    if (vkEndCommandBuffer(commandBuffer) != VK_SUCCESS) {
        throw std::runtime_error("failed to record command buffer!");
    }
}




void Graphics::Renderer::drawFrame()
{
    vkWaitForFences(m_cxt.device, 1, &m_cxt.inFlightFences[m_cxt.currentFrame], VK_TRUE, UINT64_MAX);
    vkResetFences(m_cxt.device, 1, &m_cxt.inFlightFences[m_cxt.currentFrame]);


    

    uint32_t imageIndex;


    
    VkResult result = vkAcquireNextImageKHR(m_cxt.device, m_cxt.swapchain, UINT64_MAX, m_cxt.imageAvailableSemaphores[m_cxt.currentFrame], VK_NULL_HANDLE, &imageIndex);

    if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR || m_cxt.framebufferResized)
    {
        m_cxt.framebufferResized = false;
        recreateSwapChain();
    }
    else if (result != VK_SUCCESS) 
    {
        throw std::runtime_error("failed to aquire swap chain image");
    }

    vkResetCommandBuffer(m_cxt.commandBuffers[m_cxt.currentFrame], 0);
    recordCommandBuffer(m_cxt.commandBuffers[m_cxt.currentFrame], imageIndex);


    VkSubmitInfo submitInfo{};
    submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

    VkSemaphore waitSemaphores[] = {m_cxt.imageAvailableSemaphores[m_cxt.currentFrame]};
    VkPipelineStageFlags waitStages[] = {VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
    submitInfo.waitSemaphoreCount = 1;
    submitInfo.pWaitSemaphores = waitSemaphores;
    submitInfo.pWaitDstStageMask = waitStages;

    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers = &m_cxt.commandBuffers[m_cxt.currentFrame];

    VkSemaphore signalSemaphores[] = {m_cxt.renderFinishedSemaphores[m_cxt.currentFrame]};
    submitInfo.signalSemaphoreCount = 1;
    submitInfo.pSignalSemaphores = signalSemaphores;

    if (vkQueueSubmit(m_cxt.graphicsQueue, 1, &submitInfo, m_cxt.inFlightFences[m_cxt.currentFrame]) != VK_SUCCESS) {
        throw std::runtime_error("failed to submit draw command buffer!");
    }

    VkPresentInfoKHR presentInfo{};
    presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;

    presentInfo.waitSemaphoreCount = 1;
    presentInfo.pWaitSemaphores = signalSemaphores;

    VkSwapchainKHR swapChains[] = {m_cxt.swapchain};
    presentInfo.swapchainCount = 1;
    presentInfo.pSwapchains = swapChains;

    presentInfo.pImageIndices = &imageIndex;

    vkQueuePresentKHR(m_cxt.presentQueue, &presentInfo);

    m_cxt.currentFrame = (m_cxt.currentFrame + 1) % m_cxt.MAX_FRAMES_IN_FLIGHT;



    // VkResult result = vkAcquireNextImageKHR(m_cxt.device, m_cxt.swapchain, UINT64_MAX, imageAvailableSemaphores[currentFrame], VK_NULL_HANDLE, &imageIndex);


    // // needs work
    // if (result == VK_ERROR_OUT_OF_DATE_KHR) 
    // {
    //     recreateSwapChain();
    //     return;
    // } 
    // else if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR) 
    // {
    //     throw std::runtime_error("failed to acquire swap chain image!");
    // }
    // // for later


    // vkAcquireNextImageKHR(m_cxt.device, m_cxt.swapchain, UINT64_MAX, m_cxt.imageAvailableSemaphore, VK_NULL_HANDLE, &imageIndex);

    // vkResetCommandBuffer(m_cxt.commandBuffer, /*VkCommandBufferResetFlagBits*/ 0);
    // recordCommandBuffer(m_cxt.commandBuffer, imageIndex);

    // VkSubmitInfo submitInfo{};
    // submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

    // VkSemaphore waitSemaphores[] = {m_cxt.imageAvailableSemaphore};
    // VkPipelineStageFlags waitStages[] = {VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
    // submitInfo.waitSemaphoreCount = 1;
    // submitInfo.pWaitSemaphores = waitSemaphores;
    // submitInfo.pWaitDstStageMask = waitStages;

    // submitInfo.commandBufferCount = 1;
    // submitInfo.pCommandBuffers = &m_cxt.commandBuffer;

    // VkSemaphore signalSemaphores[] = {m_cxt.renderFinishedSemaphore};
    // submitInfo.signalSemaphoreCount = 1;
    // submitInfo.pSignalSemaphores = signalSemaphores;

    // if (vkQueueSubmit(m_cxt.graphicsQueue, 1, &submitInfo, m_cxt.inFlightFence) != VK_SUCCESS) {
    //     throw std::runtime_error("failed to submit draw command buffer!");
    // }

    // VkPresentInfoKHR presentInfo{};
    // presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;

    // presentInfo.waitSemaphoreCount = 1;
    // presentInfo.pWaitSemaphores = signalSemaphores;

    // VkSwapchainKHR swapChains[] = {m_cxt.swapchain};
    // presentInfo.swapchainCount = 1;
    // presentInfo.pSwapchains = swapChains;

    // presentInfo.pImageIndices = &imageIndex;

    // vkQueuePresentKHR(m_cxt.presentQueue, &presentInfo);
}   





void Graphics::Renderer::recreateSwapChain()
{
    vkDeviceWaitIdle(m_cxt.device);

    Core::vksetup::cleanupSwapChain(m_cxt);

    Core::vksetup::createSwapChain(m_cxt);
    Core::vksetup::createImageViews(m_cxt);
    Core::vksetup::createFramebuffers(m_cxt);
}

