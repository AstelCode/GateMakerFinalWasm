//
// Created by MSI on 8/07/2026.
//

#include "RectCollider.h"

namespace Engine::Colliders {
    RectCollider::RectCollider(double width, double height) : Collider(width, height) {
    }

    RectCollider::RectCollider(std::shared_ptr<Vector> &position, double width, double height) : Collider(
        position, width, height) {
    }

    void RectCollider::width(double width) {
        _width = width;
    }

    void RectCollider::height(double height) {
        _height = height;
    }


    bool RectCollider::pointInside(int x, int y) {
        double dx = x - _position->x;
        double dy = y - _position->y;
        return (
            -_width / 2 <= dx && dx <= _width / 2 &&
            -_height / 2 <= dy && dy <= _height / 2
        );
    }
}
