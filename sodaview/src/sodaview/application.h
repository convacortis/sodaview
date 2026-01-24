#pragma once

// main application namespace (window, init ect)
namespace sodaview 
{

    class application
    {
    
    public:
        
        application();
        ~application();

        void run();

    private:
    
        // pointers to window which will be managed by arena eventually
        

        void setup();
        // bool initArena();
        bool initWindow();
        void kill();

        // condition that controls game loop
        bool m_running = true;
    };

    application* createApplication();

}