//
// Created by MSI on 16/07/2026.
//

#include "FontManager.h"

namespace Engine::FontManager {
    void FontManager::init() {
        TTF_Init();
    }

    void FontManager::addFont(FontData data) {
        fonts.insert({data.name, data});
    }

    TTF_Font *FontManager::loadFont(string name, int size) {
        auto it = fonts.find(name);
        if (it == fonts.end()) return nullptr;
        FontData &data = it->second;

        string loaded_name = name + std::to_string(size);
        auto loaded = loadedFonts.find(loaded_name);
        if (loaded != loadedFonts.end()) {
            return loaded->second;
        }


        TTF_Font *font = TTF_OpenFont(data.path.c_str(), size);
        loadedFonts[loaded_name] = font;
        return font;
    }

    void FontManager::quit() {
        for (auto &it: loadedFonts) {
            TTF_CloseFont(it.second);
        }
        TTF_Quit();
    }

    SDL_Surface *FontManager::loadFontSurface(string fontName, int size, std::string text, SDL_Color color) {
        TTF_Font *font = loadFont(fontName, size);
        SDL_Surface *surface = TTF_RenderText_Blended(
            font,
            text.c_str(),
            color
        );
        return surface;
    }

    SDL_Surface *FontManager::loadFontSurface(TTF_Font *font, std::string text, SDL_Color color) {
        SDL_Surface *surface = TTF_RenderText_Blended(
            font,
            text.c_str(),
            color
        );
        return surface;
    }
}
