//
// Created by MSI on 8/07/2026.
//

#ifndef WASM_PROJECT_RECTCOLLIDER_H
#define WASM_PROJECT_RECTCOLLIDER_H
#include "Collider.h"

namespace Engine::Colliders {
    class RectCollider : Collider {
    public:
        RectCollider(double width, double height);

        RectCollider(std::shared_ptr<Vector> &position, double width, double height);

        void width(double width);

        void height(double height);


        bool pointInside(int x, int y) override;
    };
}


#endif //WASM_PROJECT_RECTCOLLIDER_H
