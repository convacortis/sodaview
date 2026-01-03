#include "application.h"
#include <SDL2/SDL.h>
#include <iostream>




sodaview::application::application() 
{
    setup();
}

sodaview::application::~application() 
{
    kill();
}



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
    }
}






void sodaview::application::setup()
{
    if ( !initWindow() ) 
    { 
        std::cout << "Failed to create window" << std::endl; 
        m_running = false;
    }
}






bool sodaview::application::initWindow()
{

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
        SDL_WINDOW_SHOWN );
    
    if ( !window )
    {
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        return false;
    }

    surface = SDL_GetWindowSurface(window);
    if (!surface) 
    {
        std::cout << "Surface could not be created: " << SDL_GetError() << std::endl;
        return false;
    }


    SDL_FillRect( surface, NULL, SDL_MapRGB( surface->format, 255, 255, 255 ) );
    
    std::cout  << "it worked" << std::endl;
    return true;

} 



void sodaview::application::kill()
{
    SDL_FreeSurface( surface );
	SDL_DestroyWindow( window );
	SDL_Quit();
}