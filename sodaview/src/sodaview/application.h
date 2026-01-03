#pragma once

#include <SDL2/SDL.h>

namespace sodaview 
{

    class application
    {
    
    public:
        
        application();
        ~application();

        void run();

    private:

        void setup();
        bool initWindow();
        void kill();

        bool m_running = true;
        SDL_Surface* surface;
        SDL_Window* window;
    };

    application* createApplication();

}