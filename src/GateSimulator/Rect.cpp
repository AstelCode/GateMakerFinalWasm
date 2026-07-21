//
// Created by MSI on 20/07/2026.
//

#include "Rect.h"
#include "emscripten/val.h"
using namespace emscripten;
Rect::Rect(int w, int h) {
    width = w;
    height = h;
    color = {255, 0, 0, 255};
}

void Rect::init() {
    Entity::init();
    initTexture();
}

void Rect::initTexture() {
    Renderer *renderer = getContext<Engine::EngineContext>()->renderer;
    texture = renderer->generateTargetTexture(width, height);
    renderer->drawIn(texture);
    SDL_SetRenderDrawColor(renderer->get(), 0, 0, 0, 0);
    SDL_RenderClear(renderer->get());
    SDL_Rect rect = {0, 0, width, height};
    SDL_SetRenderDrawColor(renderer->get(), color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer->get(), &rect);
    renderer->endDrawing();

}

void Rect::update() {
}

void Rect::draw() {
    Renderer *renderer = getContext<Engine::EngineContext>()->renderer;
    SDL_Rect rect = {0, 0, width, height};
    renderer->renderTexture(texture, transform, rect);
}
