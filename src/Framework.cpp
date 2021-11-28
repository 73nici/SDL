#include <Framework.h>

/**
 * returns the current SDL_Renderer
 * @return SDL_Renderer
 */
SDL_Renderer *Framework::getRenderer() {
    return this->renderer;
}

/**
 * returns the current SDL_Window
 * @return SDL_Window
 */
SDL_Window *Framework::getWindow() {
    return this->window;
}

/**
 * cleans up SDL on exit
 */
void Framework::cleanUp() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

/**
 * renders the current image
 */
void Framework::render() {
    SDL_RenderPresent(this->renderer);
}

/**
 * prepares the render for the next image
 */
void Framework::prepare() {
    SDL_RenderClear(this->renderer);
}

/**
 * prepares the render for the next image with background color
 * @param r red color between 0 and 255
 * @param g green color between 0 and 255
 * @param b blue color between 0 and 255
 * @param a alpha channel between 0 and 255
 */
void Framework::prepare(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a) {
    SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
    SDL_RenderClear(this->renderer);
}

/**
 * init the framework
 */
void Framework::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        Util::log(SDL_GetError());
        exit(1);
    }

    this->window = SDL_CreateWindow("SDL_CPP", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}
