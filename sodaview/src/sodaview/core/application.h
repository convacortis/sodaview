// responsible from main sodaview application class
#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <limits>
#include <optional>
#include <set>

#include "../logging/logging.h"

#include "vksetup/vksetup.h"


// main application namespace (window, init ect)
namespace Core 
{
    class Application
    {
    
    public:
        Application();
        ~Application();
        void run();

    private: 
        void setup();
        void mainLoop();
        void initVulkan();
        

        // vulkan context
        Core::vksetup::VkContext m_cxt;
        
        // condition that controls game loop
        bool m_running = true;

    };

    Application* createApplication();

}