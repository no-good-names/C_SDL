#include <stdio.h>
#include <SDL2/SDL.h>

#define elif else if // I like python elif

#define TRUE 1
#define FALSE 0

SDL_Event e;

const int WINDOW_WIDTH = 1640;
const int WINDOW_HEIGHT = 1480;

void eventHandler (int running) {
    if(e.type == SDL_QUIT) {
        running = FALSE;
    }
    if(e.type == SDL_KEYUP) {
		switch(e.key.keysym.sym) {
		    case SDLK_w:
		        printf("up\n");
				break;
			case SDLK_s:
				printf("down\n");
				break;
			case SDLK_a:
				printf("left\n");
				break;
			case SDLK_d:
				printf("right\n");
				break;
		}
    }
}

int main( int argc, char* args[] )
{
    int running = FALSE;
    SDL_Window *window = NULL;
    SDL_Surface *winSurface = NULL;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if(window == NULL) {
        printf("Window couldn't init\n");
        SDL_Quit();
    }
    else {
        winSurface = SDL_GetWindowSurface(window);
        SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, 0xFF, 0xFF, 0xFF));
        SDL_UpdateWindowSurface(window);
        running = TRUE;
    }

    while(running == TRUE) {
        while(SDL_PollEvent(&e) != 0) {
            eventHandler(running);
        }
        SDL_UpdateWindowSurface(window);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
