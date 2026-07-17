//
// Created by MSI on 16/07/2026.
//

#ifndef WASM_PROJECT_TEXT_H
#define WASM_PROJECT_TEXT_H
#include "Entity.h"

namespace Engine::Entities {
    class Text : public Entity {
    private:
        SDL_Texture *texture = nullptr;
        SDL_Rect rect;
        TTF_Font *font;
        string text;
        SDL_Color color = {0, 0, 0, 255};
        bool auto_resize = true;

    public:
        ~Text() = default;

        void x(int x);

        void y(int y);

        int w();

        int h();

        void w(int w);

        void h(int h);

        void setColor(SDL_Color color);

        void setText(string text);

        void setFont(string name, int size);

        void draw() override;

        void updateTexture();

        void update() override;
    };
}


#endif //WASM_PROJECT_TEXT_H
