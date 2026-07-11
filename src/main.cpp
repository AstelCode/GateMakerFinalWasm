#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <emscripten.h>
#include <iostream>

#include "renderer/Renderer.h"

Renderer* renderer = nullptr;

SDL_Texture* textTexture = nullptr;
SDL_Texture* textTexture1 = nullptr;

SDL_Rect textRect  = {50,  50, 0, 0};
SDL_Rect textRect1 = {50, 100, 0, 0};

bool createText(SDL_Renderer* renderer,
                TTF_Font* font,
                const char* text,
                SDL_Color color,
                SDL_Texture*& texture,
                SDL_Rect& rect)
{
    SDL_Surface* surface = TTF_RenderText_Blended(font, text, color);

    if (!surface) {
        std::cerr << "TTF_RenderText_Blended: " << TTF_GetError() << std::endl;
        return false;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);

    if (!texture) {
        std::cerr << "SDL_CreateTextureFromSurface: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(surface);
        return false;
    }

    rect.w = surface->w;
    rect.h = surface->h;

    SDL_FreeSurface(surface);
    return true;
}

void main_loop()
{
    renderer->clear(255, 255, 255, 255);

    SDL_RenderCopy(renderer->get(), textTexture,  nullptr, &textRect);
    SDL_RenderCopy(renderer->get(), textTexture1, nullptr, &textRect1);

    renderer->render();
}

int main()
{
    renderer = new Renderer(800, 600);
    renderer->init();

    if (TTF_Init() == -1) {
        std::cerr << TTF_GetError() << std::endl;
        return -1;
    }

    TTF_Font* font = TTF_OpenFont("assets/fonts/Roboto-Regular.ttf", 24);

    if (!font) {
        std::cerr << TTF_GetError() << std::endl;
        return -1;
    }

    SDL_Color color = {255, 0, 0, 255};

    createText(
        renderer->get(),
        font,
        "Hello from WebAssembly!",
        color,
        textTexture,
        textRect
    );

    createText(
        renderer->get(),
        font,
        "Hola",
        color,
        textTexture1,
        textRect1
    );

    emscripten_set_main_loop(main_loop, 0, 1);

    return 0;
}