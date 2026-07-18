//
// Created by MSI on 16/07/2026.
//
#include "Entity.h"

using namespace Engine::Entities;


shared_ptr<EngineContext> Entity::context = nullptr;

void Entity::setContext(shared_ptr<EngineContext> &_context) {
    context = _context;
}

void Entity::addChild(Entity *entity) {
    children.push_back(shared_ptr<Entity>(entity));
    transform.addChild(&entity->transform);
}

Entity::Entity() {
}

void Entity::updateTransform() {
    transform.updateChildren();
}
