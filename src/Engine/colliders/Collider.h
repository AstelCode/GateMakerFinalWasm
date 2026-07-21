//
// Created by MSI on 8/07/2026.
//

#ifndef WASM_PROJECT_COLLIDER_H
#define WASM_PROJECT_COLLIDER_H
#include "Engine/math/Vector.h"
#include <memory>

namespace Engine::Colliders {
    using Math::Vector;

    class Collider {
    protected:
        double _width, _height;
        std::shared_ptr<Vector> _position;

    public:
        virtual ~Collider() = default;

        Collider(int width, int height);

        Vector *position();

        Collider(std::shared_ptr<Vector> &position, double width, double height);

        double width();

        double height();

        // virtual ~Collider();

        virtual bool pointInside(int x, int y);
    };
}
#endif //WASM_PROJECT_COLLIDER_H
