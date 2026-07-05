//
// Created by MSI on 5/07/2026.
//

#ifndef WASM_PROJECT_RECT_H
#define WASM_PROJECT_RECT_H
#include "Entity.h"

class Rect : public Entity {
private:
    int x;
    int y;
    int width;
    int height;

public:
    Rect(int width, int height);

    void set_position(int x, int y);

public:
    void draw(Canvas2D canvas) override;

    void update(long time) override;
};

#endif //WASM_PROJECT_RECT_H
