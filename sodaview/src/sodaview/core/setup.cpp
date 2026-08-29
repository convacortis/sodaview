#include "application.h"


void Core::Application::setup()
{
    if ( !Core::vksetup::initWindow(m_cxt) ) 
    { 
        LOG_FATAL("Failed to initialise window");
        m_running = false;
    }

    initVulkan(); 

    m_renderer = std::make_unique<Graphics::Renderer>(m_cxt);
}



void Core::Application::initVulkan()
{
    Core::vksetup::createInstance(m_cxt);
    Core::vksetup::setupDebugMessenger(m_cxt);
    Core::vksetup::createSurface(m_cxt);
    Core::vksetup::pickPhysicalDevice(m_cxt);
    Core::vksetup::createLogicalDevice(m_cxt);
    Core::vksetup::createSwapChain(m_cxt);
    Core::vksetup::createImageViews(m_cxt);
    Core::vksetup::createRenderPass(m_cxt);
    Core::vksetup::createGraphicsPipeline(m_cxt);
    Core::vksetup::createFramebuffers(m_cxt);
    Core::vksetup::createCommandPool(m_cxt);
    Core::vksetup::createCommandBuffer(m_cxt);
    Core::vksetup::createSyncObjects(m_cxt);
}