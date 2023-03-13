//Using SDL, SDL_image and standard IO
#include <stdio.h>
#include <SDL.h>

#define TRUE 1
#define FALSE 0

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main( int argc, char* args[] )
{
    int running = FALSE;
    SDL_Window *window = NULL;
    SDL_Event event;

    if(SDL_Init(SDL_INIT_VIDEO)) {
        running = TRUE;
    }

    window = SDL_CreateWindow("SDL window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

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