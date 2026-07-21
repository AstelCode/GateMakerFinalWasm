//
// Created by MSI on 5/07/2026.
//

#include "App.h"

#include <SDL2/SDL_events.h>



namespace Engine {
    using Engine::Entities::Text;

    App::App() {
        TextureAtlas::TextureAtlas::setRenderer(shared_ptr<Renderer::Renderer>(&renderer));
        TextureManager::TextureManager::setRenderer(shared_ptr<Renderer::Renderer>(&renderer));
    }

    App::~App() {
        fontManager.quit();
    }

    void App::init() {
        renderer.init();
        fontManager.init();
        textureAtlas.init();
        loadFonts();
        initContext();
        Entity::setContext(context);
        initEntities();
        tree.init();
    }

    void App::initContext() {
        context = make_shared<EngineContext>();
        context->renderer = &renderer;
        context->keyboard = &keyboard;
        context->mouse = &mouse;
        context->font_manager = &fontManager;
        context->tree = &tree;
        context->texture_manager = &textureManager;
        context->texture_atlas = &textureAtlas;
    }

    void App::initEntities() {
        if (show_fps) {
            fpsDisplay = new Text();
            fpsDisplay->setFont("Roboto-Regular", 23);
            fpsDisplay->transform.localMatrix.setTransform(1, 0, 0, 0);
        }
    }

    void App::loadFonts() {
        fontManager.addFont({"Roboto-Regular", "assets/fonts/Roboto-Regular.ttf"});
    }

    void App::capture_events() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_MOUSEMOTION:
                    mouse.mouse_move(event.motion.x, event.motion.y);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    mouse.mouse_down(event.motion.x, event.motion.y, event.button.button);
                    break;
                case SDL_MOUSEBUTTONUP:
                    mouse.mouse_up(event.motion.x, event.motion.y, event.button.button);
                    break;
                case SDL_MOUSEWHEEL:
                    mouse.wheel(event.wheel.x, event.wheel.y);
                    break;
                case SDL_KEYDOWN:
                    keyboard.capture_keyboard(0, event.key.keysym.sym);
                    break;
                case SDL_KEYUP:
                    keyboard.capture_keyboard(1, event.key.keysym.sym);
                    break;
            }
        }
    }

    void App::loop() {
        renderer.clear(255, 255, 255, 255);
        update();
        tree.update();
        if (show_fps) {
            fpsCounter.update();
            fpsDisplay->setText("FPS: " + std::to_string(fpsCounter.getFPS()));
            fpsDisplay->updateTexture();
            fpsDisplay->update();
            fpsDisplay->draw();
        }
        renderer.render();
    }

    void App::update() {
    }

    void App::resize(int width, int height) {
        renderer.resize(width, height);
    }
}
