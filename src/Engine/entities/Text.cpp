//
// Created by MSI on 16/07/2026.
//

#include "Text.h"


int Entities::Text::w() {
    return rect.w;
}

int Entities::Text::h() {
    return rect.h;
}

void Entities::Text::w(int w) {
    rect.w = w;
}

void Entities::Text::h(int h) {
    rect.h = h;
}

void Entities::Text::x(int x) {
    rect.x = x;
}

void Entities::Text::y(int y) {
    rect.y = y;
}

void Entities::Text::setColor(SDL_Color color) {
    this->color = color;
}

void Entities::Text::setText(string text) {
    this->text = text;
}

void Entities::Text::setFont(string name, int size) {
    FontManager::FontManager *font_manager = context->font_manager;
    font = font_manager->loadFont(name, size);
}

void Entities::Text::draw() {
    //     rect.x = _x;
    //     rect.y = _y;
    SDL_Renderer *renderer = context->renderer->get();
    if (texture) {
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }
}

void Entities::Text::updateTexture() {
    SDL_Renderer *renderer = context->renderer->get();
    SDL_Surface *surface = TTF_RenderText_Blended(
        this->font,
        text.c_str(),
        color
    );
    if (texture) {
        SDL_DestroyTexture(texture);
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (auto_resize) {
        rect.w = surface->w;
        rect.h = surface->h;
    }
    SDL_FreeSurface(surface);
}

void Entities::Text::update() {
}

// void Entities::Text::update() {
// }
