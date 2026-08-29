// responsible from main sodaview application class
#pragma once


#include <memory>

#include "vksetup/vksetup.h"
#include "../graphics/renderer/renderer.h"


// main application namespace (window, init ect)
namespace Core 
{
    class Application
    {
    
    public:
        Application();
        virtual ~Application();
        void run();

    private: 
        void setup();
        void mainLoop();
        void initVulkan();
        

        // vulkan context
        Core::vksetup::VkContext m_cxt;
        std::unique_ptr<Graphics::Renderer> m_renderer;
        
        // condition that controls game loop
        bool m_running = true;

    };

    Application* createApplication();

}