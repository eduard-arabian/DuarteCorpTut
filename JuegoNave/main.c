#include <SDL2/SDL.h>
#include <stdio.h>

#ifdef __MINGW32__
#undef main
#endif

#define XSIZE 600
#define YSIZE 600
#define MS 10

typedef struct Ship Ship;
typedef struct Missile Missile;

struct Ship
{
    int x1, y1; // coordinate 1
    int x2, y2; // coordinate 2
    int x3, y3; // coordinate 3
    int vx, vy; // speed
    Missile *missiles;
};

struct Missile
{
    int x1, y1;
    int x2, y2;
    int vx, vy;
};

int main(void)
{
    int exit_code = EXIT_SUCCESS;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", SDL_GetError(), NULL);
        SDL_Quit();
        exit_code = EXIT_FAILURE;
    } else {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "OK", "SDL started", NULL);
    }

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event event;
    int gameOver = 0;
    int typeEvent = 0;
    const unsigned char *keys = NULL;

    window = SDL_CreateWindow("Ship",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              XSIZE,
                              YSIZE,
                              SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    keys = SDL_GetKeyboardState(NULL);

    while (!gameOver) {
        // events
        if (SDL_PollEvent(&event)) {
            typeEvent = event.type;
            if (typeEvent == SDL_QUIT) {
                gameOver = 1;
            } else if (typeEvent == SDL_MOUSEBUTTONDOWN) {
                if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
                    //gameOver = 1;
                }
            } else if (typeEvent == SDL_KEYDOWN) {
                if (keys[SDL_SCANCODE_ESCAPE]) {
                    gameOver = 1;
                } else if (keys[SDL_SCANCODE_LEFT]) {
                } else if (keys[SDL_SCANCODE_RIGHT]) {
                } else if (keys[SDL_SCANCODE_UP]) {
                } else if (keys[SDL_SCANCODE_DOWN]) {
                } else if (keys[SDL_SCANCODE_SPACE]) {
                }
            }
        }
        // screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(MS);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return exit_code;
}
