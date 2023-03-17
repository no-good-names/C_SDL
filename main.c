#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

#define TRUE 1
#define FALSE 0

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main( int argc, char* args[] )
{
    int running = FALSE;
    SDL_Window *window = NULL;
    SDL_Surface* winSurface = NULL;
    SDL_Event event;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Could not init: %s", SDL_GetError);
        return 1;
    } else {
        window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

        if( window == NULL) {
            printf("Window couldn't init: %s", SDL_GetError);
        }

        winSurface = SDL_GetWindowSurface( window );
        SDL_FillRect( winSurface, NULL, SDL_MapRGB( winSurface->format, 0xFF, 0xFF, 0xFF ) );
        SDL_UpdateWindowSurface( window );
        running = TRUE;
    }

    while(running == TRUE) {
        while(SDL_PollEvent(&event) != 0) {
            if(event.type == SDL_QUIT) {
                running = FALSE;
            }
        }
        SDL_UpdateWindowSurface(window);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
