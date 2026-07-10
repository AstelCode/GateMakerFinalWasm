//
// Created by MSI on 8/07/2026.
//

#ifndef WASM_PROJECT_RECTCOLLIDER_H
#define WASM_PROJECT_RECTCOLLIDER_H
#include "Collider.h"


class RectCollider:Collider {
public:
    RectCollider(double width, double height);
    ~RectCollider() override;

    bool pointInside(Vector &vector) override;
};


#endif //WASM_PROJECT_RECTCOLLIDER_H
