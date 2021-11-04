#include <Framework.h>

SDL_Renderer *Framework::getRenderer() {
    return this->renderer;
}

SDL_Window *Framework::getWindow() {
    return this->window;
}

void Framework::cleanUp() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void Framework::render() {
    SDL_RenderPresent(this->renderer);
}

void Framework::prepare() {
    SDL_RenderClear(this->renderer);
}


void Framework::prepare(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a) {
    SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
    SDL_RenderClear(this->renderer);
}

void Framework::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        Util::log(SDL_GetError());
        exit(1);
    }

    this->window = SDL_CreateWindow("SDL_CPP", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Framework::drawLine(const int x0, const int y0, const int xe, const int ye) {
    const int dx = xe -x0;
    const int dy = ye - y0;
    int d = 2 * dy - dx;
    const int incrE = 2 * dy;
    const int incrNE = 2 * (dy -dx);
    int y = y0;
    SDL_SetRenderDrawColor(this->renderer, 255, 255, 0, 0);
    SDL_RenderDrawPoint(this->renderer, x0, y0);

    for (int x = x0; x < xe; x++) {
        if (d <= 0) {
            d += incrE;
        } else {
            d += incrNE;
            y++;
        }

        SDL_RenderDrawPoint(this->renderer, x, y);
    }
}
