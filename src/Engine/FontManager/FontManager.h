//
// Created by MSI on 16/07/2026.
//

#ifndef WASM_PROJECT_FONTMANAGER_H
#define WASM_PROJECT_FONTMANAGER_H
#include "FontData.h"
#include <map>
#include <SDL_ttf.h>

namespace Engine::FontManager {
    class FontManager {
    public:
        void init();

        void addFont(FontData data);

        TTF_Font *loadFont(string name, int size);

        void quit();

        SDL_Surface *loadFontSurface(string font, int size, std::string text, SDL_Color color);

        SDL_Surface *loadFontSurface(TTF_Font *font, std::string text, SDL_Color color);

    private:
        map<string, FontData> fonts;
        map<string, TTF_Font *> loadedFonts;
    };
}


#endif //WASM_PROJECT_FONTMANAGER_H
