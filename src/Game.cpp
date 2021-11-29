#include <Game.h>

/**
 * the game loop
 * @return 0 on exit
 */
int Game::loop() {
    bool running = true;

    Enemy enemy = Enemy();
    this->enemies.push_back(enemy);

    while (running) {
        Uint32 startTick = SDL_GetTicks();
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;

                case SDL_KEYDOWN:
                    if (event.key.keysym.scancode == SDL_SCANCODE_Q) {
                        running = false;
                    }
                    break;
            }

        }

        g_framework->prepare(0, 0, 0, 255);

        player.update();

        this->updateEnemies(player.getShots());

        g_framework->render();

        Util::log(SDL_GetTicks() - startTick);
    }

    return 0;
}

/**
 * updates the list of enemies
 * @param shots the list of shots fired by the player
 */
void Game::updateEnemies(std::list<Shot> shots) {
    std::list<Enemy>::iterator it;

    for (it = this->enemies.begin(); it != this->enemies.end(); it++) {
        if (!it->processShots(shots) || it->getPosY() >= SCREEN_HEIGHT) {
            this->enemies.erase(it--);
        } else {
            it->update();
        }
    }
}
