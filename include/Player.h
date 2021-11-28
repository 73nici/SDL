#ifndef SDL_CPP_PLAYER_H
#define SDL_CPP_PLAYER_H

#include <iostream>
#include <list>
#include <SDL2/SDL.h>

#include <Framework.h>
#include <Shot.h>
#include <Util.h>
#include <Sprite.h>

class Player : Sprite {
private:
    SDL_Texture *shootTexture = nullptr;
    std::list<Shot> shots = {};
    bool isShooting = false;

    void move();
    void shoot();
    void processShooting();
public:
    Player();
    void update();
    std::list<Shot> getShots() {
        return this->shots;
    }

};


#endif //SDL_CPP_PLAYER_H
