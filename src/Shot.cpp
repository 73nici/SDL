//
// Created by johncena on 10/26/21.
//
#include <Shot.h>

Shot::Shot(const int posX, const int posY) {
    this->rect = {posX - (SHOT_WIDTH / 2), posY, SHOT_HEIGHT, SHOT_HEIGHT};
    this->surface = SDL_LoadBMP("./assets/shoot.bmp");

    Util::log(SDL_GetError());
    this->texture = SDL_CreateTextureFromSurface(g_framework->getRenderer(), this->surface);


    SDL_FreeSurface(this->surface);
}

// in dem Destruktor ist irwas falsch
Shot::~Shot() {
    // std::cout << SDL_GetError() << std::endl << "hi" << std::endl;
    // SDL_DestroyTexture(this->texture);
}

void Shot::update() {
    SDL_RenderCopy(g_framework->getRenderer(), this->texture, nullptr, &this->rect);
}
