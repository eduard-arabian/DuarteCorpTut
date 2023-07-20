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

    SDL_Window *window;
    SDL_Renderer *renderer;

    window = SDL_CreateWindow("Ship",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              XSIZE,
                              YSIZE,
                              SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    return exit_code;
}
