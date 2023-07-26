#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>
#include <SDL.h>
#include <math.h>

#include "maintype.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define RECT_SPEED 500.0
#define TARGET_DELTATIME 16.67
#define RECT_SIZE 50

typedef struct {
    float x;
    float y;
} Camera;

static struct {
    SDL_Window *g_window;
    SDL_Renderer *g_renderer;
    SDL_Texture *g_texture;
    bool quit;
    bool sleepy;
    Camera camera;
} state;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    double W_CENTERX = WINDOW_WIDTH / 2 - (RECT_SIZE / 2);
    double W_CENTERY = WINDOW_HEIGHT / 2 - (RECT_SIZE / 2);

    state.g_window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    state.g_renderer = SDL_CreateRenderer(state.g_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_FRect player = {W_CENTERX, W_CENTERY, RECT_SIZE, RECT_SIZE};
    SDL_Event event;

    state.quit = false;
    u32 lastTime = SDL_GetTicks();

    while (!state.quit) {
        u32 currentTime = SDL_GetTicks();
        double deltaTime = (currentTime - lastTime) * .001;

        if (deltaTime > TARGET_DELTATIME) {
            double d_deltaTime = deltaTime - TARGET_DELTATIME;
            SDL_Delay(d_deltaTime);
        }

        lastTime = currentTime;

        while(SDL_PollEvent(&event)) {
            switch (event.type)
            {
            case SDL_QUIT:
                state.quit = true;
                break;
            
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
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

        double vel = (double)(deltaTime * RECT_SPEED);

        const u8 *keystate = SDL_GetKeyboardState(NULL);

        if (keystate[SDL_SCANCODE_UP]) {
            player.y -= vel;
        }
        if (keystate[SDL_SCANCODE_DOWN]) {
            player.y += vel;
        }
        if (keystate[SDL_SCANCODE_LEFT]) {
            player.x -= vel;
        }
        if (keystate[SDL_SCANCODE_RIGHT]) {
            player.x += vel;
        }
        // Color
        SDL_SetRenderDrawColor(state.g_renderer, 0, 0, 0, 255);
        SDL_RenderClear(state.g_renderer);

        SDL_SetRenderDrawColor(state.g_renderer, 0, 255, 0, 255);
        SDL_RenderFillRectF(state.g_renderer, &player);
        // Update the screen
        SDL_RenderPresent(state.g_renderer);
    }

    // Clean up resources
    SDL_DestroyRenderer(state.g_renderer);
    SDL_DestroyWindow(state.g_window);
    SDL_Quit();

    return 0;
}
