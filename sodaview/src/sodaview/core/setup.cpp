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
}




// create window
bool Core::Application::initWindow()
{
  
} 


void Core::Application::createTriangle()
{
    

}