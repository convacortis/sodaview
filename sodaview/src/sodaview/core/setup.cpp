#include "../logging/logging.h"
#include "application.h"



void Core::Application::setup()
{
    // if ( !initArena() )
    // {
    //     LOG_FATAL("Arena could not be created");
    //     m_running = false;
    // }

    if ( !initWindow() ) 
    { 
        LOG_FATAL("Failed to initialise window");
        m_running = false;
    }

    initVulkan(); 
    
}




// create window with glfw
bool Core::Application::initWindow()
{
    // initialise glfw
    glfwInit();

    int platform = glfwGetPlatform();

    glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_WAYLAND);

    // do not create opengl context
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    
    // disable window resizing
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // shows the window
    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);

    // create window
    window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);

    glfwShowWindow(window);  // explicitly show it
    glfwFocusWindow(window); // and focus it

    LOG_INFO("Successfully initialised window");

    return true;
    
} 

void Core::Application::initVulkan()
{
    

}


