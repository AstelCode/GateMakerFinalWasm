//
// Created by MSI on 8/07/2026.
//

#include "AABB.h"

AABB::AABB(Vector min, Vector max) {
}

bool AABB::intersect(const AABB &otra) const {
    return (min.x <= otra.max.x && max.x >= otra.min.x) &&
       (min.y <= otra.max.y && max.y >= otra.min.y);
}

void AABB::combinar(const AABB &hijo) {
}
