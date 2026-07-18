//
// Created by MSI on 17/07/2026.
//
#pragma once
#ifndef WASM_PROJECT_ENTITYTREE_H
#define WASM_PROJECT_ENTITYTREE_H
#include <map>
#include "Engine/entities/Entity.h"
#include <vector>
using namespace std;

namespace Engine::Entities {
    class Entity;
}

using namespace Engine::Entities;


namespace Engine {
    class EntityTree {
    public:
        void addEntity(Entity* entity);
        void registerEntity(string key, Entity* entity);
        void update();

        shared_ptr<Entity> findEntity(string key);
    private:
        map<string, shared_ptr<Entity>> entitiesRegister;
        vector<shared_ptr<Entity>> entities;
    };
}


#endif //WASM_PROJECT_ENTITYTREE_H
