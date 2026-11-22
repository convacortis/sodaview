#include "vksetup.h"

void Core::vksetup::cleanupSwapChain(VkContext& cxt)
{
    for (auto framebuffer : cxt.swapChainFramebuffers)
    {
        vkDestroyFramebuffer(cxt.device, framebuffer, nullptr);
    }

    for (auto imageView : cxt.swapChainImageViews)
    {
        vkDestroyImageView(cxt.device, imageView, nullptr);
    }

    vkDestroySwapchainKHR(cxt.device, cxt.swapchain, nullptr);
}


// kill application cleanly
void Core::vksetup::cleanup(VkContext& cxt)
{

    cleanupSwapChain(cxt);
    
    vkDestroyPipeline(cxt.device, cxt.graphicsPipeline, nullptr);
    vkDestroyPipelineLayout(cxt.device, cxt.pipelineLayout, nullptr);
    
    
    
    for (size_t i = 0; i < cxt.MAX_FRAMES_IN_FLIGHT; i++) {
        vkDestroySemaphore(cxt.device, cxt.renderFinishedSemaphores[i], nullptr);
        vkDestroySemaphore(cxt.device, cxt.imageAvailableSemaphores[i], nullptr);
        vkDestroyFence(cxt.device, cxt.inFlightFences[i], nullptr);
    }

    
    
    vkDestroyRenderPass(cxt.device, cxt.renderPass, nullptr);
    
    
    vkDestroyCommandPool(cxt.device, cxt.commandPool, nullptr);
    
    vkDestroyDevice(cxt.device, nullptr);
    
    if (enableValidationLayers) 
    {
        destroyDebugUtilsMessengerEXT(cxt.instance, cxt.debugMessenger, nullptr);
    }

    vkDestroySurfaceKHR(cxt.instance, cxt.surface, nullptr);
    vkDestroyInstance(cxt.instance, nullptr);
    
    glfwDestroyWindow(cxt.window);
    
    glfwTerminate();
}