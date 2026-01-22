#pragma once

namespace sodaview 
{

    class application
    {
    
    public:
        
        application();
        ~application();

        void run();

    private:
    
        SDL_Surface* surface;
        SDL_Window* window;
        SDL_GLContext glContext;

        void setup();
        bool initWindow();
        void kill();

        bool m_running = true;
    };

    application* createApplication();

}