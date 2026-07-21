//
// Created by MSI on 8/07/2026.
//

#include "AABB.h"

namespace Engine::Colliders {
    AABB::AABB(std::shared_ptr<Vector> &position) {
        _position = position;
    }

    AABB::AABB() {
        _position = std::make_shared<Vector>(0, 0);
        _left = 0;
        _right = 0;
        _top = 0;
        _bottom = 0;
    }

    AABB::AABB(double minX, double minY, double maxX, double maxY) {
        _position = std::make_shared<Vector>(0, 0);
        _right = (maxX - minX) / 2;
        _left = -_right;
        _bottom = (maxY - minY) / 2;
        _top = -_bottom;
    }

    void AABB::combine(AABB &hijo) {
        _left = min(hijo._left, _left);
        _right = max(hijo._right, _right);
        _top = min(hijo._top, _top);
        _bottom = max(hijo._bottom, _bottom);
    }

    void AABB::combine(Collider &collider) {
        double cx = collider.position()->x;
        double cy = collider.position()->y;
        double right = cx + collider.width() / 2;
        double left = cx - collider.width() / 2;
        double bottom = cy + collider.height() / 2;
        double top = cy - collider.height() / 2;
        _left = min(left, _left);
        _right = max(right, _right);
        _top = min(top, _top);
        _bottom = max(bottom, _bottom);
    }

    void AABB::combine(ColliderManager &manager) {
        for (Area &area: manager.getAllAreas()) {
            combine(*area.collider);
        }
    }

    void AABB::combine(double minX, double minY, double maxX, double maxY) {
        double cx = (maxX + minX) / 2;
        double cy = (maxY + minY) / 2;
        double right = cx + (maxX - minX) / 2;
        double left = cx - (maxX - minX) / 2;
        double bottom = cy + (maxY - minY) / 2;
        double top = cy - (maxY - minY) / 2;

        _left = min(left, _left);
        _right = max(right, _right);
        _top = min(top, _top);
        _bottom = max(bottom, _bottom);
    }

    bool AABB::pointInside(int x, int y) {
        return (_left <= x && x <= _right) && (_top <= y && y <= _bottom);
    }
}
