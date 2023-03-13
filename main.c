// SDL2 C++ convert to C
// Have to download SDL2 your self!
#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_image.h>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main( int argc, char* args[] )
{
  SDL_Window *window = NULL;
  bool running = false;
  SDL_Event event;
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Could not init video: %s\n", SDL_GetError);
    return 1;
  }
  else {
    running = true;
  }
  window = SDL_CreateWindow("SDL window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
  while(running == true) {
    while(SDL_PollEvent(&event) != 0) {
      if(event.type == SDL_QUIT) {
        running = false;
      }
    }
    SDL_UpdateWindowSurface(window);
  }
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
