#include <stdio.h>
#include <string>
#include <iostream>

#include "../../../vendor/glad/include/glad/glad.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include "logging.h"
#include "application.h"

SDL_Surface* surface;
SDL_Window* window;
SDL_GLContext glContext;


// opengl shaders

const char* vertexShaderSource = "#Version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#Version 330 core\n"
"out vec3 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.2f, 1.0f);\n"
"}\0";


// create and destroy application
sodaview::application::application() 
{
    setup();
}

sodaview::application::~application() 
{
    LOG_INFO("Killed program cleanly");
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
bool sodaview::application::initWindow()
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    if ( SDL_Init( SDL_INIT_EVERYTHING  ) < 0 )
    {
        LOG_FATAL("Error initialising SDL: %s", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow( 
        "sodaview", 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        700, 
        600, 
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
    );

    if ( !window )
    {
        LOG_FATAL("Failed to create window: %s", SDL_GetError());
        return false;
    }
    
    SDL_GLContext context = SDL_GL_CreateContext(window);

    if ( !context )
    {
        LOG_FATAL("Failed to create OpenGL context: %s", SDL_GetError());
        return false;
    }

    surface = SDL_GetWindowSurface(window);
    if (!surface) 
    {
        LOG_FATAL("Failed to create window surface: %s", SDL_GetError());
        return false;
    }


    SDL_FillRect( surface, NULL, SDL_MapRGB( surface->format, 255, 1, 255 ) );

   
    gladLoadGL();

    glViewport(0, 0, 700, 800);

    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    LOG_INFO("Successully initialised window");
    return true;

} 


void sodaview::application::createTriangle()
{
    
    
    GLfloat vertices[] =
    {
        -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
        0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
        0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f
    };

}

// kill application cleanly
void sodaview::application::kill()
{
    SDL_FreeSurface( surface );
	SDL_DestroyWindow( window );
	SDL_Quit();
}