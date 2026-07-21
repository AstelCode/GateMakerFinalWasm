//
// Created by MSI on 20/07/2026.
//

#include "TextureAtlas.h"

namespace Engine::TextureAtlas {
    using Renderer::Renderer;

    void TextureAtlas::setRenderer(shared_ptr<Renderer> _renderer) {
        renderer = _renderer;
    }

    void TextureAtlas::init() {
        bitmap.resize(b_width, vector<bool>(b_height, false));
        texture = renderer->generateTargetTexture(CELL_SIZE * b_width, CELL_SIZE * b_height);
    }

    TextureArea TextureAtlas::reserve(string name, int width, int height) {
        int w = ceil((double) width / CELL_SIZE);
        int h = ceil((double) height / CELL_SIZE);
        bool valid = false;
        int i = 0, j = 0;
        for (i = 0; i <= b_width - w; i++) {
            for (j = 0; j <= b_height - h; j++) {
                valid = true;
                for (int k = 0; k < w; k++) {
                    for (int l = 0; l < h; l++) {
                        if (bitmap[k + i][l + j]) valid = false;
                    }
                    if (!valid) break;
                }
                if (valid) {
                    break;
                }
            }
            if (valid) {
                break;
            }
        }
        if (valid) {
            TextureArea area = {
                i,
                j,
                w,
                h
            };
            textureAreas.insert({name, area});
            return area;
        }
        return {};
    }

    void TextureAtlas::freeTextureArea(TextureArea &textureArea) {
        for (int x = 0; x < textureArea.w; x++) {
            for (int y = 0; y < textureArea.h; y++) {
                bitmap[x + textureArea.x][y + textureArea.y] = false;
            }
        }
    }

    void TextureAtlas::beginDrawing() {
        renderer->drawIn(texture);
    }

    void TextureAtlas::endDrawing() {
        renderer->endDrawing();
    }

    void TextureAtlas::draw(TextureArea &textureArea, SDL_Rect &rect, Math::Transform &transform) {
        SDL_Rect source = {
            textureArea.x * CELL_SIZE,
            textureArea.y * CELL_SIZE,
            textureArea.w * CELL_SIZE,
            textureArea.h * CELL_SIZE
        };
        renderer->renderTexture(
            texture,
            transform,
            source,
            rect
        );
    }

    void TextureAtlas::draw(string name, SDL_Rect &rect, Math::Transform &transform) {
        auto it = textureAreas.find(name);
        if (it == textureAreas.end()) return;
        TextureArea &area = it->second;
        SDL_Rect source = {
            area.x * CELL_SIZE,
            area.y * CELL_SIZE,
            area.w * CELL_SIZE,
            area.h * CELL_SIZE
        };
        renderer->renderTexture(
            texture,
            transform,
            source,
            rect
        );
    }

    void TextureAtlas::quit() {
        SDL_DestroyTexture(texture);
    }


    shared_ptr<Renderer> TextureAtlas::renderer = nullptr;
    int TextureAtlas::CELL_SIZE = 64.0;
}
