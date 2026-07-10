//
// Created by MSI on 8/07/2026.
//

#ifndef WASM_PROJECT_AABB_H
#define WASM_PROJECT_AABB_H
#include "../math/Vector.h"

class AABB {
public:
    Vector min;
    Vector max;
    AABB(Vector min, Vector max);
    bool intersect(const AABB &otra) const;
    void combinar(const AABB& hijo);
};



#endif //WASM_PROJECT_AABB_H
