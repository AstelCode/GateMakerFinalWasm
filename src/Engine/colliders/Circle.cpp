//
// Created by MSI on 15/07/2026.
//

#include "Circle.h"
using namespace Engine::Colliders;

Circle::Circle(double radius) : Collider(radius * 2, radius * 2) {
    this->_radius = radius;
}

Circle::Circle(std::shared_ptr<Vector> &position, double radius) : Collider(
    position, radius * 2, radius * 2) {
}

double Circle::radius() {
    return _radius;
}

void Circle::radius(double radius) {
    _width = radius * 2;
    _height = radius * 2;
    _radius = radius;
}

bool Circle::pointInside(int x, int y) {
    auto v = _position->clone();
    (*v).x = x - (*v).x;
    (*v).y = y - (*v).y;
    if (v->length() <= this->_radius) {
        return true;
    }
    return false;
}
