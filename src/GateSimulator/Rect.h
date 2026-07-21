//
// Created by MSI on 20/07/2026.
//

#ifndef WASM_PROJECT_RECT_H
#define WASM_PROJECT_RECT_H
#include  "Engine/entities/Entity.h"

class Rect : public Engine::Entities::Entity {
public:
    SDL_Texture *texture;
    SDL_Color color;

    int width, height;
    Rect(int width, int h);

    void init() override;

    void initTexture();

    void update() override;

    void draw() override;
};


#endif //WASM_PROJECT_RECT_H
