//
// Created by johncena on 10/26/21.
//

#include "Shot.h"

Shot::Shot(const int posX, const int posY) {
    this->rect = {posX - (SHOT_WIDTH / 2), posY, 20, 20};
    this->surface = SDL_LoadBMP("./shoot.bmp");

    std::cout << SDL_GetError() << std::endl;
    this->texture = SDL_CreateTextureFromSurface(g_framework->getRenderer(), this->surface);


    SDL_FreeSurface(this->surface);
}

void Shot::update() {
    SDL_RenderCopy(g_framework->getRenderer(), this->texture, nullptr, &this->rect);
}
