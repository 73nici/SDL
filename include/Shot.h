//
// Created by johncena on 10/26/21.
//

#ifndef SDL_CPP_SHOT_H
#define SDL_CPP_SHOT_H

#include <SDL2/SDL.h>

#include <Framework.h>
#include <Util.h>

#define SHOT_WIDTH 20
#define SHOT_HEIGHT 20

class Shot {
private:
    SDL_Rect rect = {};
    SDL_Surface *surface = nullptr;
    SDL_Texture *texture = nullptr;

public:
    Shot(int posX, int posY);

    ~Shot();

    int getPosX() {
        return this->rect.x;
    }

    int getPosY() {
        return this->rect.y;
    }

    void setPosX(int posX) {
        this->rect.x = posX;
    }

    void setPosY(int posY) {
        this->rect.y = posY;
    }

    void update();
};


#endif //SDL_CPP_SHOT_H
