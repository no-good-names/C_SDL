// SDL2 C++ convert to C
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>

#define TRUE 0
#define FALSE 1

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main( int argc, char* args[] )
{
  SDL_Window *window = NULL;
  int running = FALSE;
  SDL_Event event;
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Could not init video: %s\n", SDL_GetError);
  }
  else {
    window = SDL_CreateWindow("SDL window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
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
