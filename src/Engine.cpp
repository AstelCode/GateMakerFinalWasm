//
// Created by MSI on 5/07/2026.
//

#include "Engine.h"
#include "math/Vector.h"

Engine::Engine(val htmlCanvas) : canvas(htmlCanvas), textureAtlas(50, 50) {
    //entities.push_back(std::make_unique<Rect>(100, 100));
    SpriteRegion region = textureAtlas.allocate(200, 200);
    textureAtlas.use(region);
    //val console = val::global("console");
    //console.call<void>("log", region.x, region.y, region.width, region.height);
    Canvas2D *canvas = &textureAtlas.tempCanvas();
    canvas->fillRect(10,10,200,200);
    textureAtlas.loadSprite();
    this->region = region;
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

    textureAtlas.draw(canvas,region,80,80,200,100);

    for (const auto &e: entities) {
        e->update(time);
        e->draw(canvas);
    }
}
