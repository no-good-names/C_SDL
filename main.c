#include <SDL2/SDL.h>
#include <stdio.h>

#define false 0
#define true 1

// Window values
const int WINDOW_WIDTH = 480;
const int WINDOW_HEIGHT = 360;

// Input cap
const int NUM_KEYS = 4;

// Rect values
const int RECT_WIDTH = 50;
const int RECT_HEIGHT = 50;
const int RECT_SPEED = 5;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);

  window = SDL_CreateWindow("window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  SDL_Rect rect = {50, 50, RECT_WIDTH, RECT_HEIGHT};
  int quit = false;
  int keys[NUM_KEYS] = {false};
  SDL_Event event;

  // FPS cap sets
  int fps = 60;
  int frameDelay = 1000 / fps;
  Uint32 frameStart;
  int frameTime;

  // Game loop
  while (!quit) {
    frameStart = SDL_GetTicks();
    // Inputs
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        quit = true;
        break;

      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_ESCAPE:
          quit = true;
          break;

        case SDLK_UP:
          keys[0] = true;
          break;

        case SDLK_DOWN:
          keys[1] = true;
          break;

        case SDLK_LEFT:
          keys[2] = true;
          break;

        case SDLK_RIGHT:
          keys[3] = true;
          break;

        default:
          break;
        }
        break;
      case SDL_KEYUP:
        switch (event.key.keysym.sym) {
        case SDLK_UP:
          keys[0] = false;
          break;

        case SDLK_DOWN:
          keys[1] = false;
          break;

        case SDLK_LEFT:
          keys[2] = false;
          break;

        case SDLK_RIGHT:
          keys[3] = false;
          break;

        default:
          break;
        }
        break;
      default:
        break;
      }
      break;
    }
    // Input handler
    if (keys[0]) {
      rect.y -= RECT_SPEED;
    }
    if (keys[1]) {
      rect.y += RECT_SPEED;
    }
    if (keys[2]) {
      rect.x -= RECT_SPEED;
    }
    if (keys[3]) {
      rect.x += RECT_SPEED;
    }
    // rendering
    // Background
    SDL_SetRenderDrawColor(renderer, 15, 15, 15, 255);
    SDL_RenderClear(renderer);
    // Rect color
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);

    // FPS cap
    frameTime = SDL_GetTicks() - frameStart;
    if (frameDelay > frameTime) {
      SDL_Delay(frameDelay - frameTime);
    }
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
