#include <SDL2/SDL.h>
#include <stdio.h>

#ifdef __MINGW32__
#undef main
#endif

#define XSIZE 600
#define YSIZE 600

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

    int typeEvent = 0;
    int gameOver = 0;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event event;

    window = SDL_CreateWindow("Ship",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              XSIZE,
                              YSIZE,
                              SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    while (!gameOver) {
        if (SDL_PollEvent(&event)) {
            typeEvent = event.type;
            if (typeEvent == SDL_QUIT) {
                gameOver = 1;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return exit_code;
}
