#include <Game.h>

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

        g_framework->prepare(0, 0, 0, 255);

        player.update();

        g_framework->render();

        Util::log(SDL_GetTicks() - startTick);
    }

    return 0;
}
