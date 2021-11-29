#include "Enemy.h"

/**
 * Moves the enemy 1 step down towards the player
 */
void Enemy::move() {
    this->rect.y += 1;
}

/**
 * Checks if the current fired shots kills some enemies
 * @param shots the list of all shots
 * @return true if enemy is still alive otherwise false
 */
bool Enemy::processShots(std::list<Shot> shots) {
    std::list<Shot>::iterator it;
    for (it = shots.begin(); it != shots.end(); it++) {
        // check if shot hits the enemy Y-axis and X-axis
        if ((this->getPosY() <= it->getPosY()) && (this->getPosY() + this->getHeight() >=  it->getPosY())  && (this->getPosX() <= it->getPosX()) && (this->getPosX() + this->getWidth() >= it->getPosX())){
                return false;
        }
    }
    return true;
}

/**
 * Called before each render
 */
void Enemy::update() {
    this->move();
    SDL_RenderCopy(g_framework->getRenderer(), this->texture, nullptr, &this->rect);
}

