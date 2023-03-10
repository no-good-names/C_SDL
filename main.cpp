#include <SDL.h>
#include <stdio.h>

//Screen dimension
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main(int argc, char* args[])
{
	SDL_Window* window = NULL;

	SDL_Surface* screenSurface = NULL;

	if( SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf( "SDL init error.\nSDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		window = SDL_CreateWindow("SDL window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN );
		if(window == NULL) {
			printf("Window couldn't be created.\nSDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);

			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			SDL_UpdateWindowSurface( window );

            //Keep window up
            SDL_Event event;
            bool quit = false;
            while( quit == false ){
                while( SDL_PollEvent( &event ) ){
                    if( event.type == SDL_QUIT ) quit = true;
                }
            }
		}
	}

	SDL_DestroyWindow( window );

	SDL_Quit();

	return 0;
}
