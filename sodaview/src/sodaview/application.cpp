#include "../../../vendor/glad/include/glad/glad.h"
#include "../../../vendor/SDL/include/SDL.h"
#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "logging.h"
#include "application.h"



// create and destroy application
sodaview::application::application() 
{
    setup();
}

sodaview::application::~application() 
{
    kill();
}

// event loop
void sodaview::application::run()
{
    while(m_running)
    {
        SDL_Event event;
        
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) 
            {
                m_running = false;
            }
        }

        SDL_UpdateWindowSurface(window);
        
        SDL_Delay(10);
    }
}

// run all things needed to setup project
void sodaview::application::setup()
{
    if ( !initWindow() ) 
    { 
        std::cout << "Failed to create window" << std::endl; 
        m_running = false;
    }
}

// create window
bool sodaview::application::initWindow()
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    if ( SDL_Init( SDL_INIT_EVERYTHING  ) < 0 )
    {
        std::cout << "Error initialising SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow( 
        "sodaview", 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        1280, 
        720, 
        SDL_WINDOW_SHOWN 
    );

    if ( !window )
    {
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        return false;
    }
    
    SDL_GLContext glContext = SDL_GL_CreateContext(window);

    if (!glContext)
    {
        std::cout << "Error creating OpenGL content: " << SDL_GetError() << std::endl;
        return false;
    }

    surface = SDL_GetWindowSurface(window);
    if (!surface) 
    {
        std::cout << "Surface could not be created: " << SDL_GetError() << std::endl;
        return false;
    }


    SDL_FillRect( surface, NULL, SDL_MapRGB( surface->format, 255, 1, 255 ) );
    
    std::cout  << "it worked" << std::endl;
    return true;

} 

// kill application cleanly
void sodaview::application::kill()
{
    SDL_FreeSurface( surface );
	SDL_DestroyWindow( window );
	SDL_Quit();
}