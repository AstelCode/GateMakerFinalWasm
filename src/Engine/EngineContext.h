//
// Created by MSI on 16/07/2026.
//

#ifndef WASM_PROJECT_ENGINECONTEXT_H
#define WASM_PROJECT_ENGINECONTEXT_H

#include "controllers/Mouse.h"
#include "controllers/Keyboard.h"
#include "FontManager/FontManager.h"
#include "renderer/Renderer.h"
using namespace Engine::Controllers;
using namespace Engine::FontManager;
using namespace Engine::Renderer;
namespace Engine {
    struct EngineContext {
        Mouse * mouse;
        Keyboard * keyboard;
        Renderer::Renderer * renderer;
        FontManager::FontManager * font_manager;
    };
}
#endif //WASM_PROJECT_ENGINECONTEXT_H
