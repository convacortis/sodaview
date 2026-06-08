#include <stdio.h>
#include <string>
#include <iostream>

#include "../logging/logging.h"
#include "application.h"




// create and destroy application
Sodaview::Application::Application() 
{
    setup();
}

Sodaview::Application::~Application() 
{
    LOG_INFO("Killed program cleanly");
    kill();
}

// event loop
void Sodaview::Application::run()
{
    while(m_running)
    {
        LOG_INFO("its working")
    }
}

// run all things needed to setup project
void Sodaview::Application::setup()
{
    // if ( !initArena() )
    // {
    //     LOG_FATAL("Arena could not be created");
    //     m_running = false;
    // }

    // if ( !initWindow() ) 
    // { 
    //     LOG_FATAL("Failed to initialise window");
    //     m_running = false;
    // }
}

// create window
bool Sodaview::Application::initWindow()
{
  
} 


void Sodaview::Application::createTriangle()
{
    

}

// kill application cleanly
void Sodaview::Application::kill()
{

}