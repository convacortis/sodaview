#include "application.h"

void Core::Application::mainLoop()
{
    while(m_running)
    {
        while (!glfwWindowShouldClose(window)) 
            {
                glfwPollEvents();
                // drawFrame();
        
            }
    }
}
