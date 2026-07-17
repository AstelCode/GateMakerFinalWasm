//
// Created by MSI on 15/07/2026.
//

#include "ColliderManager.h"
using namespace Engine::Colliders;

void ColliderManager::addArea(Area area) {
    areas.push_back(area);
}

bool ColliderManager::getArea(int x, int y, Area &area) {
    for (Area _area: areas) {
        if (_area.collider->pointInside(x, y)) {
            area = _area;
            return true;
        }
    }
    return false;
}

vector<Area> ColliderManager::getAllAreas() {
    return areas;
}
