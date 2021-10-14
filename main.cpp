#include <Framework.h>
#include <Game.h>

int main() {
    g_framework->init();
    auto *game = new Game();

    game->loop();

    g_framework->cleanUp();
    return 0;
}