#include <Player.h>

/**
 * Constructor of Player class
 */
Player::Player() : Sprite("./assets/sample.bmp", (SCREEN_WIDTH - 25) / 2, SCREEN_HEIGHT - 50, 50, 50) {
    SDL_Surface *surfaceShoot = SDL_LoadBMP("./assets/shoot.bmp");

    if (surfaceShoot == nullptr) {
        Util::logSDLError();
        exit(1);
    }
    this->shootTexture = SDL_CreateTextureFromSurface(g_framework->getRenderer(), surfaceShoot);

    SDL_FreeSurface(surfaceShoot);
}

/**
 * checks the keyboard state and moves the player
 */
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

/**
 * checks the keyboard state and shoots
 */
void Player::shoot() {
    const Uint8 *state = SDL_GetKeyboardState(nullptr);

    if (state[SDL_SCANCODE_SPACE] && !this->isShooting) {
        this->isShooting = true;
        Shot shot = Shot(this->rect.x + (this->rect.w / 2), this->rect.y, this->shootTexture);
        this->shots.push_back(shot);
    }

    if (!state[SDL_SCANCODE_SPACE]) {
        this->isShooting = false;
    }

}

/**
 * update function for the player called on every render
 */
void Player::update() {
    this->move();
    this->shoot();
    this->processShooting();
    SDL_RenderCopy(g_framework->getRenderer(), this->texture, nullptr, &this->rect);
}

/**
 * checks if the shoots are still in range
 */
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