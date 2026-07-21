//
// Created by MSI on 20/07/2026.
//

#ifndef WASM_PROJECT_TEXTUREATLAS_H
#define WASM_PROJECT_TEXTUREATLAS_H
#include "Engine/renderer/Renderer.h"
#include <memory>
#include <map>

using namespace Engine::Renderer;

namespace Engine::TextureAtlas {
    using namespace std;
    struct TextureArea {
        int x, y, w, h;
    };

    class TextureAtlas {
    public:
        static void setRenderer(shared_ptr<Renderer::Renderer> _renderer);

        void init();
        TextureArea reserve(string name, int width, int height);
        void freeTextureArea(TextureArea &textureArea);
        void beginDrawing();
        void endDrawing();
        void draw(TextureArea &textureArea, SDL_Rect &rect, Math::Transform &transform);
        void draw(string name,SDL_Rect &rect, Math::Transform &transform);

        void quit();

        static int cellSize;
    private:
        int b_width = 1024, b_height = 1024;
        vector<vector<bool>> bitmap;
        map<string, TextureArea> textureAreas;
        SDL_Texture *texture = nullptr;

    private:
        static shared_ptr<Renderer::Renderer> renderer;
        static int CELL_SIZE;
    };
}


#endif //WASM_PROJECT_TEXTUREATLAS_H
