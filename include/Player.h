#ifndef SDL_CPP_PLAYER_H
#define SDL_CPP_PLAYER_H

#include <SDL2/SDL.h>
#include <iostream>

#include "./Framework.h"

class Player {
private:
    SDL_Rect rect = {0, 0, 50, 50};
    SDL_Surface *surface = nullptr;
    SDL_Texture *texture = nullptr;

    void move();
public:
    Player();
    void update();
};


#endif //SDL_CPP_PLAYER_H
