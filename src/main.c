#include <SDL2/SDL.h>
#include <stdio.h>

#define elif else if // I like python elif

#define TRUE 1
#define FALSE 0

SDL_Event event;

const int WINDOW_WIDTH = 400;
const int WINDOW_HEIGHT = 300;

void eventHandler(int isRunning) {
	while (SDL_PollEvent(&event) != FALSE) {
		if (event.type == SDL_QUIT) {
			isRunning = false;
		}
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE:
				isRunning = FALSE;
				break;
			case SDLK_1:
				printf("Input test: 1\n");
				break;
			}
		}
	}
}

int main(int argc, char *args[]) {
	int isRunning = FALSE;
	SDL_Window *window = NULL;
	SDL_Surface *winSurface = NULL;

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		printf("Window couldn't init\n: %s", SDL_GetError);
		SDL_Quit();
	} else {
		isRunning = TRUE;
	}

	winSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, 0xFF, 0xFF, 0xFF));

	while (isRunning) {
		eventHandler(isRunning);
		SDL_UpdateWindowSurface(window);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
