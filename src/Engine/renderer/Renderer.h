//
// Created by MSI on 11/07/2026.
//

#ifndef WASM_PROJECT_RENDERER_H
#define WASM_PROJECT_RENDERER_H
#include <SDL2/SDL.h>
#include <iostream>

namespace Engine::Renderer {
    class Renderer {

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        int width, height;

    public:
        Renderer(int width, int height);
        void init();
        void clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
        void render();
        void destroy();
        SDL_Renderer* get();
    };
}


#endif //WASM_PROJECT_RENDERER_H
