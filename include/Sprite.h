#ifndef SDL_CPP_SPRITE_H
#define SDL_CPP_SPRITE_H

#include <SDL2/SDL.h>
#include <string>

#include <Framework.h>
#include <Util.h>

class Sprite {
public:
    /**
    * the texture for the sprite
    */
    SDL_Texture *texture;

    /**
     * the size of the texture
     */
    SDL_Rect rect;

    /**
     * returns the height of the sprite
     * @return height of sprite
     */
    int getHeight() {
        return this->rect.h;
    }

    /**
     * returns the width of the sprite
     * @return width of sprite
     */
    int getWidth() {
        return this->rect.w;
    }

    /**
     * returns the position X of the sprite
     * @return posX of sprite
     */
    int getPosX() {
        return this->rect.x;
    }

    /**
     * returns the position Y of the sprite
     * @return posY of the sprite
     */
    int getPosY() {
        return this->rect.y;
    }

    /**
     * Constructor for Sprite class
     * @param path to image file (BMP file)
     * @param x position of the sprite
     * @param y position of the sprite
     * @param w width of the sprite
     * @param h height of the sprite
     */
    Sprite(const char *path, const int x, const int y, const int w, const int h) {
        SDL_Surface *surface = nullptr;
        surface = SDL_LoadBMP(path);

        if (surface == nullptr) {
            Util::logSDLError();
            exit(1);
        }

        this->texture = SDL_CreateTextureFromSurface(g_framework->getRenderer(), surface);
        this->rect = { x, y, w, h };

        SDL_FreeSurface(surface);
    }

    /**
     * Constructor for Sprite class
     * @param texture SDL_Texture for Sprite
     * @param x position of the sprite
     * @param y position of the sprite
     * @param w width of the sprite
     * @param h height of the sprite
     */
    Sprite(SDL_Texture *texture, const int x, const int y, const int w, const int h) {
        if (texture == nullptr) {
            Util::logSDLError();
            exit(1);
        }

        this->texture = texture;
        this->rect = { x, y, w, h };
    }
};


#endif //SDL_CPP_SPRITE_H
