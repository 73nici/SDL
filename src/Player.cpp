#include <Player.h>

void Player::move() {
    const Uint8 *state = SDL_GetKeyboardState(nullptr);

    // move up
    if (state[SDL_SCANCODE_W]) {
        std::cout << "hi" << std::endl;
        this->rect.y -= 1;
    }
}

void Player::update() {
    this->move();


    SDL_SetRenderDrawColor(g_framework->getRenderer(), 255, 255, 0, 255);
    SDL_RenderFillRect(g_framework->getRenderer(), &this->rect);

}



