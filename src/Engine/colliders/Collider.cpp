//
// Created by MSI on 8/07/2026.
//

#include "Collider.h"
using namespace Engine::Colliders;

Collider::Collider(int width, int height) {
    _width = width;
    _height = height;
    _position = std::make_shared<Vector>(0,0);
}

Vector * Collider::position() {
    return _position.get();
}

Collider::Collider(std::shared_ptr<Vector> &position, double width, double height) {
    _position = position;
    _width = width;
    _height = height;
}

double Collider::width() {
    return _width;
}

double Collider::height() {
    return _height;
}
