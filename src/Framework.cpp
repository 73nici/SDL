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
    SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 255);
    SDL_RenderClear(this->renderer);
}

void Framework::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << SDL_GetError() << std::endl;
        exit(1);
    }

    this->window = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_OPENGL);
    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}
