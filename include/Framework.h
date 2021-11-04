#ifndef SDL_CPP_FRAMEWORK_H
#define SDL_CPP_FRAMEWORK_H

#include <SDL2/SDL.h>
#include <iostream>

#include <Singleton.h>
#include <Util.h>

#define g_framework Framework::Get()

#define SCREEN_HEIGHT 400
#define SCREEN_WIDTH 640

class Framework : public TSingleton<Framework> {
private:
    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;


public:

    void init();
    void cleanUp();
    void prepare(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void prepare();
    void render();
    void drawLine(int x0, int y0, int xe, int ye);

    SDL_Renderer *getRenderer();
    SDL_Window *getWindow();
};


#endif //SDL_CPP_FRAMEWORK_H
