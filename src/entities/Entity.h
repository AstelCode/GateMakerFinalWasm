//
// Created by MSI on 5/07/2026.
//

#ifndef WASM_PROJECT_ENTITY_H
#define WASM_PROJECT_ENTITY_H

#include "core/Canvas2D.h"

class Entity {
public:
    virtual void update(long time) = 0;

    virtual void draw(Canvas2D canvas) = 0;
};


#endif //WASM_PROJECT_ENTITY_H
