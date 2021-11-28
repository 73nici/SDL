#ifndef SDL_CPP_GAME_H
#define SDL_CPP_GAME_H

#include <SDL2/SDL.h>
#include <iostream>
#include <list>

#include <Player.h>
#include <Enemy.h>
#include <Framework.h>

class Game {
private:
    std::list<Enemy> enemies;
    Player player;

    void updateEnemies(std::list<Shot> shots);

public:
    int loop();
};


#endif //SDL_CPP_GAME_H
