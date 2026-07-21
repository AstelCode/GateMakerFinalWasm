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

// namespace Engine::Entities {
//     class Entity;
// }
//
// using namespace Engine::Entities;


namespace Engine {
    using Entities::Entity;
    class EntityTree {
    public:
        void addEntity(Entity* entity);
        void registerEntity(string key, Entity* entity);
        void update();
        void init();

        template<typename T>
        shared_ptr<T> findEntity(string key);
    private:
        map<string, shared_ptr<Entity>> entitiesRegister;
        vector<shared_ptr<Entity>> entities;
    };


    template<typename T>
    shared_ptr<T> EntityTree::findEntity(string key) {
        auto pair = entitiesRegister.find(key);
        if (pair == entitiesRegister.end()) {
            return nullptr;
        }
        return std::static_pointer_cast<T>(pair->second);
    }
}


#endif //WASM_PROJECT_ENTITYTREE_H
