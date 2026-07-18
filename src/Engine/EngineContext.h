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
#include "Tree/EntityTree.h"

using namespace Engine::Controllers;
using namespace Engine::FontManager;
using namespace Engine::Renderer;
namespace Engine {
    class EntityTree;
}

using namespace Engine;


namespace Engine {
    struct EngineContext {
        Mouse * mouse;
        Keyboard * keyboard;
        Renderer::Renderer * renderer;
        FontManager::FontManager * font_manager;
        EntityTree * tree;
    };
}
#endif //WASM_PROJECT_ENGINECONTEXT_H
