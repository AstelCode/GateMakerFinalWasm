//
// Created by MSI on 11/07/2026.
//

#ifndef WASM_PROJECT_RENDERER_H
#define WASM_PROJECT_RENDERER_H
#include <SDL2/SDL.h>
#include <iostream>
#include "Engine/math/Transform.h"

namespace Engine::Renderer {
    class Renderer {
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        int width, height;

    public:
        Renderer();

        void init();

        void clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

        void resize(int width, int height);

        void render();

        void destroy();

        void renderTexture(SDL_Texture *texture, Math::Transform &transform, SDL_Rect &rect);
        void renderTexture(SDL_Texture *texture, Math::Transform &transform,SDL_Rect &soruce, SDL_Rect &rect);

        void generateTexture(SDL_Texture *&texture, SDL_Surface *surface);


        SDL_Texture* generateTargetTexture(int width, int height);
        SDL_Texture* generateStaticTexture(int width, int height);
        SDL_Texture* generateStreamTexture(int width, int height);

        void drawIn(SDL_Texture *texture);
        void endDrawing();

        SDL_Renderer *get();
    };
}


#endif //WASM_PROJECT_RENDERER_H
