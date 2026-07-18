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
    SDL_Renderer *renderer = context->renderer->get();

    if (!texture)
        return;

    SDL_Rect dst = rect;

    TransformData globalTransform = transform.getGlobal();
    dst.x = static_cast<int>(globalTransform.x);
    dst.y = static_cast<int>(globalTransform.y);
    dst.w = static_cast<int>(rect.w * globalTransform.scale);
    dst.h = static_cast<int>(rect.h * globalTransform.scale);
    SDL_Point center{
        dst.w / 2,
        dst.h / 2
    };

    SDL_RenderCopyEx(
        renderer,
        texture,
        nullptr,
        &dst,
        globalTransform.angle * 180.0 / M_PI, // SDL usa grados
        &center,
        SDL_FLIP_NONE
    );
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
