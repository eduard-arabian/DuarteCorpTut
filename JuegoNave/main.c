#include <SDL2/SDL.h>
#include <stdio.h>

#ifdef __MINGW32__
#undef main
#endif

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

    return exit_code;
}
