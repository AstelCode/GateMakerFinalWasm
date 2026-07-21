//
// Created by MSI on 20/07/2026.
//

#include "TextureManager.h"
namespace Engine::TextureManager {
    using Engine::Renderer::Renderer;
    void TextureManager::loadTexture(string name, string path) {
        SDL_Texture *texture = IMG_LoadTexture(renderer->get(), path.c_str());
        if (!texture) {
            SDL_Log("Error: %s", IMG_GetError());
        }
        textures[name] = texture;
    }

    void TextureManager::loadBMPTexture(string name, string path) {
        SDL_Surface *surface = SDL_LoadBMP(path.c_str());
        SDL_Texture *texture;
        renderer->generateTexture(texture, surface);
        SDL_FreeSurface(surface);
        textures[name] = texture;
    }

    void TextureManager::freeTexture(string name) {
        auto pair = textures.find(name);
        if (pair == textures.end()) return;
        SDL_DestroyTexture(pair->second);
        textures.erase(pair);
    }

    void TextureManager::freeAllTextures() {
        for (auto &pair: textures) {
            SDL_DestroyTexture(pair.second);
        }
        textures.clear();
    }

    void TextureManager::setRenderer(shared_ptr<Renderer> _renderer) {
        renderer = _renderer;
    }

    shared_ptr<Renderer> TextureManager::renderer = nullptr;
}
