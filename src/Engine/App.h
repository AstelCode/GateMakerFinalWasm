//
// Created by MSI on 5/07/2026.
//

#ifndef WASM_PROJECT_ENGINE_H
#define WASM_PROJECT_ENGINE_H


#include "controllers/Mouse.h"
#include "controllers/Keyboard.h"
#include "entities/Entity.h"
#include "FontManager/FontManager.h"
#include "renderer/Renderer.h"
#include "utils/FPSCounter.h"
#include <memory>
#include "Engine/TextureAtlas/TextureAtlas.h"

#include "TextureManager/TextureManager.h"
#include "tree/EntityTree.h"
#include "entities/Text.h"
namespace Engine {
    class App {
    protected:
        Mouse mouse;
        Keyboard keyboard;
        Renderer::Renderer renderer;
        FontManager::FontManager fontManager;
        Utils::FPSCounter fpsCounter;
        TextureManager::TextureManager textureManager;
        shared_ptr<EngineContext> context;
        EntityTree tree;
        TextureAtlas::TextureAtlas textureAtlas;
        Entities::Text *fpsDisplay;

    protected:
        bool show_fps = true;

    public:
        App();

        virtual ~App();

        virtual void init();

        void initContext();

        virtual void initEntities();

        virtual void loadFonts();

        void capture_events();

        void loop();

        virtual void update();


        void resize(int width, int height);
    };
}

#endif //WASM_PROJECT_ENGINE_H
