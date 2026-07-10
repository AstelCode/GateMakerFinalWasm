//
// Created by MSI on 8/07/2026.
//

#ifndef WASM_PROJECT_COLLIDER_H
#define WASM_PROJECT_COLLIDER_H
#include "math/Vector.h"

class Collider {
protected:
    double width, height;
    Vector *position;

public:
    virtual ~Collider();

    virtual bool pointInside(Vector &vector);
};


#endif //WASM_PROJECT_COLLIDER_H
