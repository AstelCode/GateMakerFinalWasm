//
// Created by MSI on 5/07/2026.
//
#pragma once
#ifndef WASM_PROJECT_ENTITY_H
#define WASM_PROJECT_ENTITY_H

#include "Engine/EngineContext.h"
#include "Engine/colliders/Collider.h"
#include "Engine/colliders/AABB.h"
#include "Engine/math/Transform.h"
#include  <memory>

using namespace Engine::Colliders;
using namespace Engine::Math;
using namespace Engine;
using namespace std;

namespace Engine::Entities {
    class Entity {
    protected:
        static shared_ptr<EngineContext> context;

    public:
        static void setContext(shared_ptr<EngineContext> &context);



    public:
        Collider *collider;
        Transform transform;
        AABB boundingBox;
        bool visible;
        bool is_ready;

        void addChild(Entity* entity);

        vector<shared_ptr<Entity>> children;

        Entity();

        virtual ~Entity() = default;

        virtual void update() = 0;

        void updateTransform();

        virtual void draw() = 0;
    };
}


#endif //WASM_PROJECT_ENTITY_H
