#include <Player.h>

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

void Player::update() {
    this->move();


    SDL_SetRenderDrawColor(g_framework->getRenderer(), 255, 255, 0, 255);
    SDL_RenderFillRect(g_framework->getRenderer(), &this->rect);

}



