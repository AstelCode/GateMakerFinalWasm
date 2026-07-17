//
// Created by MSI on 8/07/2026.
//

#ifndef WASM_PROJECT_AABB_H
#define WASM_PROJECT_AABB_H
#include "../math/Vector.h"
#include "Collider.h"
#include "ColliderManager.h"
#include <memory>
using namespace  Engine::Math;

namespace Engine::Colliders {
    class AABB {
    public:
        std::shared_ptr<Vector> _position;
        double _left, _right, _top, _bottom;

        AABB(std::shared_ptr<Vector> &position);

        AABB();

        AABB(double minX, double minY, double maxX, double maxY);

        bool intersect(AABB &otra) const;

        void combine(AABB &hijo);

        void combine(Collider &collider);

        void combine(ColliderManager &manager);

        void combine(double minX, double minY, double maxX, double maxY);

        bool pointInside(int x, int y);
    };
}


#endif //WASM_PROJECT_AABB_H
