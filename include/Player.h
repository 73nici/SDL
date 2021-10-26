#ifndef SDL_CPP_PLAYER_H
#define SDL_CPP_PLAYER_H

#include <SDL2/SDL.h>
#include <iostream>
#include <list>

#include "./Framework.h"
#include "./Shot.h"

class Player {
private:
    SDL_Rect rect = {(SCREEN_WIDTH - 25) / 2, SCREEN_HEIGHT - 50, 50, 50};
    SDL_Surface *surface = nullptr;
    SDL_Texture *texture = nullptr;
    std::list<Shot> shots = {};
    bool isShooting = false;

    void move();
    void shoot();
    void processShooting();
public:
    Player();
    void update();
};


#endif //SDL_CPP_PLAYER_H
