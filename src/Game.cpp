#include "Game.h"

int Game::loop() {
    bool running = true;

    while (running) {
        Uint32 startTick = SDL_GetTicks();
        SDL_Event event;

        while(SDL_PollEvent(&event)) {
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

        SDL_SetRenderDrawColor(g_framework->getRenderer(), 0, 0, 0, 255);
        SDL_RenderClear(g_framework->getRenderer());

        player.update();

        // g_framework->drawLine(0, 0, 50, 50);
        g_framework->render();
        std::cout << SDL_GetTicks() - startTick << std::endl;
    }

    return 0;
}
