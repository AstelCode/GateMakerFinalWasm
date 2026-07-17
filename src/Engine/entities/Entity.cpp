//
// Created by MSI on 16/07/2026.
//
#include "Entity.h"

using namespace  Engine::Entities;


shared_ptr<EngineContext> Entity::context = nullptr;

void Entity::setContext(shared_ptr<EngineContext>& _context) {
    context = _context;
}

Entity::Entity() {
}



