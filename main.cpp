//Using SDL, SDL_image and standard IO
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main( int argc, char* args[] )
{
  SDL_Window *window = NULL;
  bool Running = false;
  SDL_Event event;
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Could not init video: %s\n", SDL_GetError);
  }
  else {
    window = SDL_CreateWindow("SDL window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    Running = true;
  }
  while(Running == true) {
    while(SDL_PollEvent(&event) != 0) {
      if(event.type == SDL_QUIT) {
        Running = false;
      }
    }
    SDL_UpdateWindowSurface(window);
  }
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
