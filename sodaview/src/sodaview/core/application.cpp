// application lifetime commands are called here
// - calls setup which includes all the vulkan stuff but that lives in setup.cpp as this file is meant to be strictly lifetime (at the moment)

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