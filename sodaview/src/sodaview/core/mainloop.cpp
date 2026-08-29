#include "application.h"



void Core::Application::mainLoop()
{
    while(m_running && !glfwWindowShouldClose(m_cxt.window))
    {
        
            
        glfwPollEvents();
        m_renderer->drawFrame();
        
            
    }

    m_running = false;
}
