#ifndef SDL_CPP_PLAYER_H
#define SDL_CPP_PLAYER_H

#include <SDL2/SDL.h>
#include <iostream>

#include "./Framework.h"

class Player {
private:
    SDL_Rect rect = {50, 50, 50, 50};


    void move();
public:
    void update();
};


#endif //SDL_CPP_PLAYER_H
