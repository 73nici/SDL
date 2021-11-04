#ifndef SDL_CPP_GAME_H
#define SDL_CPP_GAME_H

#include <SDL2/SDL.h>
#include <iostream>

#include <Player.h>
#include <Framework.h>

// #define MY_DEBUG_MODE true

class Game {
private:
    Player player;

public:
    int loop();
};


#endif //SDL_CPP_GAME_H
