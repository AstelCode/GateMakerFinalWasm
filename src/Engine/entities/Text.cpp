//
// Created by MSI on 16/07/2026.
//

#include "Text.h"

namespace Engine::Entities {
    int Text::w() {
        return rect.w;
    }

    int Text::h() {
        return rect.h;
    }

    void Text::w(int w) {
        rect.w = w;
    }

    void Text::h(int h) {
        rect.h = h;
    }

    void Text::x(int x) {
        rect.x = x;
    }

    void Text::y(int y) {
        rect.y = y;
    }

    void Text::setColor(SDL_Color color) {
        this->color = color;
    }

    void Text::setText(string text) {
        this->text = text;
    }

    void Text::setFont(string name, int size) {
        FontManager::FontManager *font_manager = context->font_manager;
        font = font_manager->loadFont(name, size);
    }

    void Text::draw() {
        if (!texture)
            return;

        auto &renderer = getContext<EngineContext>()->renderer;
        renderer->renderTexture(texture, transform, rect);
    }

    void Text::updateTexture() {
        auto &renderer = getContext<EngineContext>()->renderer;
        auto &font_manager = getContext<EngineContext>()->font_manager;
        auto surface = font_manager->loadFontSurface(font, text, color);
        renderer->generateTexture(texture, surface);
        SDL_FreeSurface(surface);
        if (auto_resize) {
            rect.w = surface->w;
            rect.h = surface->h;
        }
    }

    void Text::update() {
    }
}
