//
// Created by MSI on 16/07/2026.
//

#ifndef WASM_PROJECT_RENDERINGENTITY_H
#define WASM_PROJECT_RENDERINGENTITY_H
#include <SDL2/SDL_render.h>
namespace Engine::Renderer {
    class RenderEntity {
    protected:
        static SDL_Renderer *renderer;
    public:
        static void setRenderer(SDL_Renderer *renderer);

    public:
        virtual ~RenderEntity();
        virtual void update();

        virtual void draw(SDL_Renderer* renderer);
    };
}



#endif //WASM_PROJECT_RENDERINGENTITY_H
