//
// Created by MSI on 5/07/2026.
//

#ifndef WASM_PROJECT_ENGINE_H
#define WASM_PROJECT_ENGINE_H

#include <vector>
#include "Mouse.h"
#include "Keyboard.h"
#include "core/Canvas2D.h"
#include "core/FPSCounter.h"
#include "entities/Entity.h"

class Engine
{
private:
    Mouse mouse;
    Keyboard keyboard;
    Canvas2D canvas;
    FPSCounter fpsCounter;
    std::vector<std::unique_ptr<Entity>> entities;

public:
    Engine(val htmlCanvas);
    void capture_mouse(int event, double _x, double _y, int button_idx);
    void capture_wheel(double deltaX, double deltaY);
    void capture_keyboard(string event, char key);

public:
    void update(long time);
};

#endif //WASM_PROJECT_ENGINE_H
