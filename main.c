#include <SDL2/SDL.h>
#include <stdio.h>

// Custom bool
#define FALSE 0
#define TRUE !FALSE

const int WIN_WIDTH = 640;
const int WIN_HEIGHT = 480;

SDL_Event event;
int isRunning = FALSE;
SDL_Window *window = NULL;
SDL_Surface *winSurface = NULL;

void puts() {
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_1:
			printf("Input: 1\n");
			break;
		case SDLK_2:
			printf("Input: 2\n");
			break;
		}
	}
}

int main(int argc, char *args[]) {
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	winSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, 0x00, 0x00, 0x00));
	SDL_UpdateWindowSurface(window);

	if (window == NULL) {
		printf("Window couldn't init: %s", SDL_GetError);
	} else {
		isRunning = TRUE;
	}

	while (isRunning == TRUE) {
		while (SDL_PollEvent(&event) != FALSE) {
			if (event.type == SDL_QUIT) {
				isRunning = FALSE;
			}
			puts();
		}
		SDL_UpdateWindowSurface(window);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
