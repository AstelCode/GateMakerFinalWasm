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


namespace Engine::Entities {
    using Colliders::Collider;
    using Colliders::AABB;
    using Math::Transform;
    using namespace std;
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

        void addChild(Entity *entity);

        vector<shared_ptr<Entity> > children;

        Entity();

        virtual ~Entity() = default;

        virtual void update() = 0;

        void updateTransform();

        virtual void draw() = 0;
        virtual void init();

        template<typename T>
        shared_ptr<T> getContext();
    };

    template<typename T>
    shared_ptr<T> Entity::getContext() {
        return std::static_pointer_cast<T>(context);
    }
}


#endif //WASM_PROJECT_ENTITY_H
