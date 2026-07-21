//
// Created by MSI on 15/07/2026.
//

#ifndef WASM_PROJECT_AREA_H
#define WASM_PROJECT_AREA_H
#include "Collider.h"

namespace Engine::Colliders {
    struct Area {
        int id;
        Collider *collider;
    };
}

#endif //WASM_PROJECT_AREA_H
