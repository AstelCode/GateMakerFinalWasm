//
// Created by MSI on 16/07/2026.
//

#include "RenderEntity.h"
using Engine::Renderer::RenderEntity;
SDL_Renderer *RenderEntity::renderer = nullptr;

void RenderEntity::setRenderer(SDL_Renderer *_renderer) {
    renderer = _renderer;
}

RenderEntity::~RenderEntity() {
}

void RenderEntity::update() {
}

void RenderEntity::draw(SDL_Renderer *renderer) {
}
