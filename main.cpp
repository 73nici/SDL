#include <Framework.h>
#include <Game.h>

int main() {
    g_framework->init();
    Game game;

    game.loop();

    g_framework->cleanUp();
    return 0;
}