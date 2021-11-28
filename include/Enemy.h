//
// Created by johncena on 11/26/21.
//

#ifndef SDL_CPP_ENEMY_H
#define SDL_CPP_ENEMY_H

#include <SDL2/SDL.h>
#include <list>

#include <Sprite.h>
#include <Shot.h>


class Enemy : Sprite {
private:
    void move();
public:
    Enemy() : Sprite("../assets/sample.bmp", (SCREEN_WIDTH - 25) / 2, 50, 50, 50) {};
    void update();
    bool processShots(std::list<Shot> shots);
};


#endif //SDL_CPP_ENEMY_H
