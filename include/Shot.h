#ifndef SDL_CPP_SHOT_H
#define SDL_CPP_SHOT_H

#include <SDL2/SDL.h>

#include <Framework.h>
#include <Util.h>
#include <Sprite.h>

#define SHOT_WIDTH 20
#define SHOT_HEIGHT 20

class Shot : Sprite {
public:
    /**
     * Constructor for Shot class
     * @param posX position X for the shot
     * @param posY position Y for the shot
     * @param texture texture for the shot
     */
    Shot(int posX, int posY, SDL_Texture *texture) : Sprite(texture, posX - (SHOT_WIDTH / 2), posY, SHOT_HEIGHT, SHOT_HEIGHT) {};

    int getPosX() {
        return this->rect.x;
    }

    int getPosY() {
        return this->rect.y;
    }

    int getHeight() {
        return this->rect.h;
    }

    int getWidth() {
        return this->rect.w;
    }

    void setPosX(int posX) {
        this->rect.x = posX;
    }

    void setPosY(int posY) {
        this->rect.y = posY;
    }

    void update() {
        SDL_RenderCopy(g_framework->getRenderer(), this->texture, nullptr, &this->rect);
    }
};


#endif //SDL_CPP_SHOT_H
