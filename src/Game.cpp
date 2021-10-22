#include "Game.h"
#include <SDL2/SDL_image.h>

int Game::loop() {
    bool running = true;
    Uint8 r = 0;

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

        r += 1;

        SDL_SetRenderDrawColor(g_framework->getRenderer(), r, 0, 0, 255);
        SDL_RenderClear(g_framework->getRenderer());


        player.update();
        

        SDL_RenderPresent(g_framework->getRenderer());
        std::cout << SDL_GetTicks() - startTick << std::endl;
    }

    return 0;
}
