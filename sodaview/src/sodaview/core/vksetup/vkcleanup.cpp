#include "vksetup.h"



// kill application cleanly
void Core::vksetup::cleanup(VkContext& cxt)
{
    vkDestroySemaphore(cxt.device, cxt.renderFinishedSemaphore, nullptr);
    vkDestroySemaphore(cxt.device, cxt.imageAvailableSemaphore, nullptr);
    vkDestroyFence(cxt.device, cxt.inFlightFence, nullptr);


    vkDestroyCommandPool(cxt.device, cxt.commandPool, nullptr);
    
    for (auto framebuffer : cxt.swapChainFramebuffers) 
    {
        vkDestroyFramebuffer(cxt.device, framebuffer, nullptr);
    }

    vkDestroyPipeline(cxt.device, cxt.graphicsPipeline, nullptr);
    vkDestroyPipelineLayout(cxt.device, cxt.pipelineLayout, nullptr);
    vkDestroyRenderPass(cxt.device, cxt.renderPass, nullptr);

    vkDestroyPipelineLayout(cxt.device, cxt.pipelineLayout, nullptr);
    
    for (auto imageView : cxt.swapChainImageViews) 
    {
        vkDestroyImageView(cxt.device, imageView, nullptr);
    }

    vkDestroySwapchainKHR(cxt.device, cxt.swapchain, nullptr);
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