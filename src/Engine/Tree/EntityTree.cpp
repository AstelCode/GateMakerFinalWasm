//
// Created by MSI on 17/07/2026.
//

#include "EntityTree.h"
using namespace Engine;

void EntityTree::addEntity(Entity *entity) {
    entities.push_back(shared_ptr<Entity>(entity));
}

void EntityTree::registerEntity(string key, Entity *entity) {
    entitiesRegister[key] = shared_ptr<Entity>(entity);
}

void EntityTree::update() {
    for (auto e: entities) {
        (*e).updateTransform();
    }

    for (auto e: entities) {
        (*e).update();
        (*e).draw();
    }
}

shared_ptr<Entity> EntityTree::findEntity(string key) {
    auto pair =  entitiesRegister.find(key);
    if (pair == entitiesRegister.end()) {
        return nullptr;
    }
    return pair->second;
}
