#include "../logging/logging.h"
#include "application.h"




// create and destroy application
Core::Application::Application() 
{
    setup();
}

Core::Application::~Application() 
{
    LOG_INFO("Killed program cleanly");
    cleanup();
}

// event loop
void Core::Application::run()
{
    while(m_running)
    {
        LOG_INFO("its working")
    }
}

// run all things needed to setup project


