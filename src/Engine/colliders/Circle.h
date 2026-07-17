//
// Created by MSI on 15/07/2026.
//

#ifndef WASM_PROJECT_CIRCLE_H
#define WASM_PROJECT_CIRCLE_H
#include "Collider.h"

namespace Engine::Colliders {
    class Circle : Collider {
        double _radius;

    public:
        Circle(double radius);
        Circle(std::shared_ptr<Vector>& position, double radius);

        double radius();
        void radius(double radius);

        bool pointInside(int x, int y) override;
    };
}


#endif //WASM_PROJECT_CIRCLE_H
