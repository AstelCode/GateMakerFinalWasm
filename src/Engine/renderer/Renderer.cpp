//
// Created by MSI on 11/07/2026.
//

#include "Renderer.h"

#include <emscripten/html5.h>
#include <emscripten/val.h>
using namespace Engine::Renderer;
using namespace emscripten;
Renderer::Renderer() {
    int width = val::global("window")["innerWidth"].as<int>();
    int height = val::global("window")["innerHeight"].as<int>();
    this->width = width;
    this->height = height;
}

void Renderer::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Error al inicializar SDL: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    SDL_CreateWindowAndRenderer(this->width, this->height, 0, &window, &renderer);
}

void Renderer::clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderClear(renderer);
}

void Renderer::render() {
    SDL_RenderPresent(renderer);
}

void Renderer::destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Renderer * Renderer::get() {
    return renderer;
}


void Renderer::resize(int width, int height) {
    this->width = width;
    this->height = height;
    emscripten_set_canvas_element_size("#canvas", width, height);
    SDL_SetWindowSize(window, width, height);
    SDL_RenderSetViewport(renderer, nullptr);
}