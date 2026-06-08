#pragma once

// main application namespace (window, init ect)
namespace Sodaview 
{

    class Application
    {
        
    
    public:
        
        Application();
        ~Application();

        void run();

    private:
    
        // pointers to window which will be managed by arena eventually
        

        void setup();

        
        // bool initArena();
        bool initWindow();
        void kill();
        void createTriangle();

        // condition that controls game loop
        bool m_running = true;


    };

    Application* createApplication();

}