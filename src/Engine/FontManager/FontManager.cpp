//
// Created by MSI on 16/07/2026.
//

#include "FontManager.h"
using namespace Engine::FontManager;

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
