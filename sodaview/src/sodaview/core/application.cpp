#include "../logging/logging.h"
#include "application.h"


Core::Application::Application()
{
    // initArena();
    LOG_INFO("Allocated memory for program")
}
Core::Application::~Application() 
{
    // cleanuparena();
    LOG_INFO("Killed program cleanly");
}


// create and destroy application
void Core::Application::run() 
{
    setup();
    mainLoop();
    cleanup();
}


void Core::Application::mainLoop()
{
    while(m_running)
    {
        LOG_INFO("its working")
    }
}

// run all things needed to setup project


