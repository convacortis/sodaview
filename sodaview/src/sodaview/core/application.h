// responsible from app creation class

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


// validation layers

const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
};

const std::vector<const char*> deviceExtensions = {
    VK_KHR_SWAPCHAIN_EXTENSION_NAME
};


// if not debug build don't include validation layers

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif







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
    

        const uint32_t WIDTH = 2000;
        const uint32_t HEIGHT = 1200;
        
        
        GLFWwindow* window;

        

        void setup();

        
        // bool initArena();


        
        bool initWindow();

        void initVulkan();

        
        void mainLoop();
        void cleanup();
        void createTriangle();

        // condition that controls game loop
        bool m_running = true;


    };

    Application* createApplication();

}