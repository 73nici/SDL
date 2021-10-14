#ifndef SDL_CPP_FRAMEWORK_H
#define SDL_CPP_FRAMEWORK_H

#include <SDL2/SDL.h>
#include <iostream>

#include <Singleton.h>

#define g_framework Framework::Get()

class Framework : public TSingleton<Framework> {
private:
    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;


public:

    void init();
    void cleanUp();
    void prepare();
    void render();

    SDL_Renderer *getRenderer();
    SDL_Window *getWindow();
};


#endif //SDL_CPP_FRAMEWORK_H
