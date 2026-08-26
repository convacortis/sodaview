// application lifetime commands are called here
// - calls setup which includes all the vulkan stuff but that lives in setup.cpp as this file is meant to be strictly lifetime (at the moment)

#include "application.h"


Core::Application::Application()
{
    LOG_INFO("Allocated memory for program")
}

Core::Application::~Application() 
{
    LOG_INFO("Killed program cleanly");
}


// create and destroy application
void Core::Application::run() 
{
    setup();
    mainLoop();
    Core::vksetup::cleanup(m_cxt);
}