#include <iostream>
#include <SDL.h>



bool init();
void kill();
bool loop();


SDL_Surface* surface;
SDL_Window* window;



int main(int argc, char** args){


    if( !init() ) return 1;


    while( loop() ){

        SDL_Delay(10);
    
    }

    kill();
	return 0;

}



bool loop(){
    
    SDL_Event e;

    while( SDL_PollEvent( &e ) != 0 ) {

		switch (e.type) {
			case SDL_QUIT:
				return false;
			case SDL_KEYDOWN:
                SDL_FillRect( surface, NULL, SDL_MapRGB( surface->format, 40, 255, 255 ) );
				break;
			case SDL_KEYUP:
                SDL_FillRect( surface, NULL, SDL_MapRGB( surface->format, 255, 40, 255 ) );
				// can also test individual keys, modifier flags, etc, etc.
				break;
			case SDL_MOUSEMOTION:
				// etc.
				break;
		}
	}

    return true;


}


void kill(){
    
    
	// Quit
    SDL_FreeSurface( surface );
	SDL_DestroyWindow( window );
	SDL_Quit();

}




bool init(){

    if ( SDL_Init( SDL_INIT_EVERYTHING  ) < 0 ){

        std::cout << "Error initialising SDL: " << SDL_GetError() << std::endl;
        return 1;

    }

    window = SDL_CreateWindow( 
            "Example", 
            SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, 
            1280, 
            720, 
            SDL_WINDOW_SHOWN );
    
    if ( !window ){

        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        return 1;

    }

    surface = SDL_GetWindowSurface(window);
    if (!surface) {
        std::cout << "Surface could not be created: " << SDL_GetError() << std::endl;
        return 1;
    }


    SDL_FillRect( surface, NULL, SDL_MapRGB( surface->format, 255, 255, 255 ) );
    
    return true;

}