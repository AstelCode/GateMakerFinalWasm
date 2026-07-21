//
// Created by MSI on 20/07/2026.
//

#ifndef WASM_PROJECT_APP_H
#define WASM_PROJECT_APP_H
#include "Engine/App.h"

class App : public Engine::App {
public:
    void update() override;

    void init();

    void initEntities();
};


#endif //WASM_PROJECT_APP_H
