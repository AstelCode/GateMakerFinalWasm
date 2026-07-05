//
// Created by MSI on 5/07/2026.
//

#include "Rect.h"

Rect::Rect(int width, int height) {
    this->width   = width;
    this->height  = height;
    this->x = 0;
    this->y = 0;
}

void Rect::set_position(int x, int y) {
    this->x = x;
    this->y = y;
}

void Rect::draw(Canvas2D canvas) {
    canvas.fillRect(x - width/2, y - height/2, width, height);
}

void Rect::update(long time) {
}
