//
// Created by MSI on 20/07/2026.
//

#include "App.h"

#include "Rect.h"

void App::update() {
}

void App::init() {
    Engine::App::init();
}

void App::initEntities() {

    Engine::App::initEntities();
    tree.addEntity(new Rect(100,100));
}
