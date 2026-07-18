//
// Created by MSI on 5/07/2026.
//

#ifndef WASM_PROJECT_ENGINE_H
#define WASM_PROJECT_ENGINE_H

#include <vector>

#include "controllers/Mouse.h"
#include "controllers/Keyboard.h"
#include "entities/Entity.h"
#include "FontManager/FontManager.h"
#include "renderer/Renderer.h"
#include "utils/FPSCounter.h"
#include <memory>

#include "entities/Text.h"
#include "Tree/EntityTree.h"

using namespace std;
using namespace Engine::Controllers;
using namespace Engine::Renderer;
using namespace Engine::Entities;
namespace Engine {
    class App
    {
    private:
        Mouse mouse;
        Keyboard keyboard;
        Renderer::Renderer renderer;
        FontManager::FontManager fontManager;
        Utils::FPSCounter fpsCounter;
        shared_ptr<EngineContext> context;
        //Text *text;
        EntityTree tree;
    public:
        App();
        ~App();
        void capture_events();
        void update();
        void resize(int width, int height);
    };
}

#endif //WASM_PROJECT_ENGINE_H
