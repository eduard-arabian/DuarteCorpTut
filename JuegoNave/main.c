#include <SDL2/SDL.h>
#include <stdio.h>

#ifdef __MINGW32__
#undef main
#endif

#define XSIZE 600
#define YSIZE 600
#define MS 10
#define SHIP_LEN 20
#define SHIP_VEL 10
#define MIS_LEN 5
#define MIS_VEL 5

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
    Missile *next;
};

void ShipDraw(Ship *ship, SDL_Renderer *renderer);
void ShipGoLeftRight(Ship *ship);
void ShipGoUpDown(Ship *ship);
void ShipFire(Ship *ship);
void MissileFired(Missile *missile);
void MissileFliedAway(Missile *missiles);

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
    Ship ship = {XSIZE / 2,
                 YSIZE / 2,
                 XSIZE / 2 - SHIP_LEN,
                 YSIZE / 2 + SHIP_LEN,
                 XSIZE / 2 + SHIP_LEN,
                 YSIZE / 2 + SHIP_LEN,
                 SHIP_VEL,
                 SHIP_VEL,
                 NULL};

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
                    ShipFire(&ship);
                }
            } else if (typeEvent == SDL_KEYDOWN) {
                if (keys[SDL_SCANCODE_ESCAPE]) {
                    gameOver = 1;
                } else if (keys[SDL_SCANCODE_LEFT]) {
                    ship.vx = -abs(ship.vx);
                    ShipGoLeftRight(&ship);
                } else if (keys[SDL_SCANCODE_RIGHT]) {
                    ship.vx = abs(ship.vx);
                    ShipGoLeftRight(&ship);
                } else if (keys[SDL_SCANCODE_UP]) {
                    ship.vy = -abs(ship.vy);
                    ShipGoUpDown(&ship);
                } else if (keys[SDL_SCANCODE_DOWN]) {
                    ship.vy = abs(ship.vy);
                    ShipGoUpDown(&ship);
                } else if (keys[SDL_SCANCODE_SPACE]) {
                    ShipFire(&ship);
                }
            }
        }
        MissileFliedAway(ship.missiles);
        // screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        ShipDraw(&ship, renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(MS);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return exit_code;
}

void ShipDraw(Ship *ship, SDL_Renderer *renderer)
{
    // draw missiles
    Missile *ixMissile = ship->missiles;
    while (ixMissile) {
        MissileFired(ixMissile);
        SDL_RenderDrawLine(renderer, ixMissile->x1, ixMissile->y1, ixMissile->x2, ixMissile->y2);
        ixMissile = ixMissile->next;
    }

    // draw ship
    SDL_Point points[4] = {{ship->x1, ship->y1}, {ship->x2, ship->y2}, {ship->x3, ship->y3}};
    points[3] = points[0];
    SDL_RenderDrawLines(renderer, points, 4);
}

void ShipGoLeftRight(Ship *ship)
{
    ship->x1 += ship->vx;
    ship->x2 += ship->vx;
    ship->x3 += ship->vx;
}

void ShipGoUpDown(Ship *ship)
{
    ship->y1 += ship->vy;
    ship->y2 += ship->vy;
    ship->y3 += ship->vy;
}

void ShipFire(Ship *ship)
{
    if (ship->missiles) {
        Missile *ixMissile = ship->missiles;
        while (ixMissile->next != NULL) {
            ixMissile = ixMissile->next;
        }
        ixMissile->next = (Missile *) SDL_malloc(sizeof(Missile));
        ixMissile = ixMissile->next;
        ixMissile->x1 = ship->x1;
        ixMissile->y1 = ship->y1;
        ixMissile->x2 = ship->x1;
        ixMissile->y2 = ship->y1 - MIS_LEN;
        ixMissile->vx = 0;
        ixMissile->vy = -MIS_VEL;
        ixMissile->next = NULL;
    } else {
        ship->missiles = (Missile *) SDL_malloc(sizeof(Missile));
        ship->missiles->x1 = ship->x1;
        ship->missiles->y1 = ship->y1;
        ship->missiles->x2 = ship->x1;
        ship->missiles->y2 = ship->y1 - MIS_LEN;
        ship->missiles->vx = 0;
        ship->missiles->vy = -MIS_VEL;
        ship->missiles->next = NULL;
    }
}

void MissileFired(Missile *missile)
{
    missile->x1 += missile->vx;
    missile->y1 += missile->vy;
    missile->x2 += missile->vx;
    missile->y2 += missile->vy;
}

void MissileFliedAway(Missile *missiles)
{
    Missile *ixMissile = missiles;
    if (ixMissile) {
        Missile *auxMissile;
        while (ixMissile->next != NULL) {
            if (ixMissile->next->y1 < 0) {
                auxMissile = ixMissile->next->next;
                SDL_free(ixMissile->next);
                ixMissile->next = auxMissile;
            } else {
                ixMissile = ixMissile->next;
            }
        }
    }
}
