//
// Created by MSI on 16/07/2026.
//

#ifndef WASM_PROJECT_ENGINECONTEXT_H
#define WASM_PROJECT_ENGINECONTEXT_H
#pragma once

#include "controllers/Mouse.h"
#include "controllers/Keyboard.h"
#include "FontManager/FontManager.h"
#include "renderer/Renderer.h"
#include "TextureManager/TextureManager.h"
#include "TextureAtlas/TextureAtlas.h"

namespace Engine::Entities {
    class Text;
}

namespace Engine {
    class EntityTree;
    // using namespace Engine;
    using Engine::Controllers::Mouse;
    using Engine::Controllers::Keyboard;
    using Engine::EntityTree;

    class EngineContext {
    public:
        Mouse *mouse;
        Keyboard *keyboard;
        Renderer::Renderer *renderer;
        FontManager::FontManager *font_manager;
        EntityTree *tree;
        TextureManager::TextureManager *texture_manager;
        TextureAtlas::TextureAtlas *texture_atlas;
    };
}
#endif //WASM_PROJECT_ENGINECONTEXT_H
