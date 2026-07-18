//
// Created by MSI on 5/07/2026.
//

#include "App.h"

#include <SDL2/SDL_events.h>

using namespace Engine;

App::App() : renderer() {
    renderer.init();
    fontManager.init();

    fontManager.addFont({"Roboto-Regular", "assets/fonts/Roboto-Regular.ttf"});

    context = make_shared<EngineContext>();
    context->renderer = &renderer;
    context->keyboard = &keyboard;
    context->mouse = &mouse;
    context->font_manager = &fontManager;
    context->tree = &tree;

    Entity::setContext(context);
    Text *text = new Text();
    text->setFont("Roboto-Regular", 23);
    tree.addEntity(text);

    text->transform.localMatrix.setTransform(1, 0, 0, 0);

    tree.registerEntity("FPS_DISPLAY", text);
}

App::~App() {
    fontManager.quit();
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

void App::update() {
    fpsCounter.update();

    renderer.clear(255, 255, 255, 255);

    // text->setText("FPS: " + std::to_string(fpsCounter.getFPS()));
    // text->updateTexture();
    Text *text = static_cast<Text *>(tree.findEntity("FPS_DISPLAY").get());
    if (text != nullptr) {
        text->setText("FPS: " + std::to_string(fpsCounter.getFPS()));
        text->updateTexture();
    }

    tree.update();
    renderer.render();
}

void App::resize(int width, int height) {
    renderer.resize(width, height);
}
