//
// Created by MSI on 5/07/2026.
//

#include "Engine.h"

#include "entities/Rect.h"

Engine::Engine(val htmlCanvas)  : canvas(htmlCanvas)
{
    entities.push_back(std::make_unique<Rect>(100, 100));
}

void Engine::capture_mouse(int event, double _x, double _y, int button_idx) {
    mouse.capture_mouse(event, _x, _y, button_idx);
}

void Engine::capture_wheel(double deltaX, double deltaY) {
    mouse.capture_wheel(deltaX, deltaY);
}

void Engine::capture_keyboard(string event, char key) {
    keyboard.capture_keyboard(event, key);
}

void Engine::update(long time) {
    canvas.clear();
    fpsCounter.update();
    canvas.drawFPS(fpsCounter.getFPS());
    Entity* base_ptr = entities[0].get();
    Rect* rect_ptr = dynamic_cast<Rect*>(base_ptr);
    if (rect_ptr != nullptr) {
        rect_ptr->set_position(mouse.get_x(), mouse.get_y());
    }

    for (const auto& e : entities) {
        e->update(time);
        e->draw(canvas);
    }
}
