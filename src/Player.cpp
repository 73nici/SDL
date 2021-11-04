#include <Player.h>

Player::Player() {
    this->surface = SDL_LoadBMP("./assets/sample.bmp");

    if (this->surface == nullptr) {
        Util::log(SDL_GetError());
        exit(1);
    }

    this->texture = SDL_CreateTextureFromSurface(g_framework->getRenderer(), this->surface);

    SDL_FreeSurface(this->surface);
}

void Player::move() {
    const Uint8 *state = SDL_GetKeyboardState(nullptr);

    // move up
    if ((state[SDL_SCANCODE_W] || state[SDL_SCANCODE_UP]) && this->rect.y > 0) {
        this->rect.y -= 1;
    }

    // move down
    if ((state[SDL_SCANCODE_S] || state[SDL_SCANCODE_DOWN]) && (this->rect.y + this->rect.h) < SCREEN_HEIGHT) {
        this->rect.y += 1;
    }

    // move left
    if ((state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT]) && this->rect.x > 0) {
        this->rect.x -= 1;
    }

    // move right
    if ((state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT]) && (this->rect.x + this->rect.w) < SCREEN_WIDTH) {
        this->rect.x += 1;
    }
}

void Player::shoot() {
    const Uint8 *state = SDL_GetKeyboardState(nullptr);

    if (state[SDL_SCANCODE_SPACE] && !this->isShooting) {
        this->isShooting = true;
        Shot shot = Shot(this->rect.x + (this->rect.w / 2), this->rect.y);
        this->shots.push_back(shot);
    }

    if (!state[SDL_SCANCODE_SPACE]) {
        this->isShooting = false;
    }

}

void Player::update() {
    this->move();
    this->shoot();
    this->processShooting();
    SDL_RenderCopy(g_framework->getRenderer(), this->texture, nullptr, &this->rect);
}

void Player::processShooting() {
    std::list<Shot>::iterator it;
    for (it = this->shots.begin(); it != this->shots.end(); it++) {
        if (it->getPosY() >= 0) {
            it->setPosY(it->getPosY() - 1);
            it->update();
        } else {
            this->shots.erase(it--);
        }
    }
}



