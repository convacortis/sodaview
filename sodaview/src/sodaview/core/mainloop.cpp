#include "application.h"

void Core::Application::mainLoop()
{
    while(m_running)
    {
        while (!glfwWindowShouldClose(m_cxt.window)) 
            {
                glfwPollEvents();
                // drawFrame();
        
            }
    }
}
