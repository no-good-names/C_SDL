#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>
#include <SDL.h>
#include "maintype.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

static struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    u32 *pixels;
    bool quit;
    bool sleepy;
} state;

static struct {
  struct {
    f32 X, Y;
  } POS;
} player;


// Rect values
const int RECT_SPEED = 5.0;

int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);

  state.window = SDL_CreateWindow("window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
  state.renderer = SDL_CreateRenderer(state.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  SDL_Rect rect = {50, 50, 50, 50};
  state.quit = false;
<<<<<<< Updated upstream
=======
  
>>>>>>> Stashed changes
  SDL_Event event;

  // Game loop
  while (!state.quit) {
    // Inputs
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        state.quit = true;
        break;
      
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:
          state.quit = true;
          break;
        
        default:
          break;
        }
      
      default:
        break;
      }
    }

    if (state.quit) {
      break;
    }

    const u8 *keystate = SDL_GetKeyboardState(NULL);

    if (keystate[SDLK_UP & 0xFFFF]) {
      rect.y -= RECT_SPEED;
    }
    if (keystate[SDLK_DOWN & 0xFFFF]) {
      rect.y += RECT_SPEED;
    }
    if (keystate[SDLK_LEFT & 0xFFFF]) {
      rect.x -= RECT_SPEED;
    }
    if (keystate[SDLK_RIGHT & 0xFFFF]) {
      rect.x += RECT_SPEED;
    }

    // rendering
    // Background
    SDL_SetRenderDrawColor(state.renderer, 15, 15, 15, 255);
    SDL_RenderClear(state.renderer);
    // Rect color
    SDL_SetRenderDrawColor(state.renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(state.renderer, &rect);
    SDL_RenderPresent(state.renderer);
  }
  SDL_DestroyRenderer(state.renderer);
  SDL_DestroyWindow(state.window);
  SDL_Quit();

  return 0;
}
