//
// Created by MSI on 20/07/2026.
//

#ifndef WASM_PROJECT_TEXTUREMANAGER_H
#define WASM_PROJECT_TEXTUREMANAGER_H
#include  <map>
#include <string>
#include <memory>
#include "Engine/renderer/Renderer.h"
#include <SDL2/SDL.h>
#include <SDL_image.h>

namespace Engine::TextureManager {
    using namespace std;
    using Renderer::Renderer;
    class TextureManager {
    public:
        void loadTexture(string name, string path);

        void loadBMPTexture(string name, string path);

        void freeTexture(string name);

        void freeAllTextures();

        static void setRenderer(shared_ptr<Renderer> renderer);
    private:
        static shared_ptr<Renderer> renderer;
        map<string, SDL_Texture*> textures;
    };
}


#endif //WASM_PROJECT_TEXTUREMANAGER_H
