//
// Created by MSI on 11/07/2026.
//

#include "Renderer.h"

#include <emscripten/html5.h>
#include <emscripten/val.h>
// using ;
using namespace emscripten;

namespace Engine::Renderer {
    Renderer::Renderer() {
        int width = val::global("window")["innerWidth"].as<int>();
        int height = val::global("window")["innerHeight"].as<int>();
        this->width = width;
        this->height = height;
    }

    void Renderer::init() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cerr << "Error al inicializar SDL: " << SDL_GetError() << std::endl;
            exit(-1);
        }

        SDL_CreateWindowAndRenderer(this->width, this->height, 0, &window, &renderer);
    }

    void Renderer::clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        SDL_SetRenderDrawColor(renderer, r, g, b, a);
        SDL_RenderClear(renderer);
    }

    void Renderer::render() {
        SDL_RenderPresent(renderer);
    }

    void Renderer::destroy() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void Renderer::renderTexture(SDL_Texture *texture, Math::Transform &transform, SDL_Rect &rect) {
        SDL_Rect dst = rect;
        TransformData globalTransform = transform.getGlobal();
        dst.x = static_cast<int>(globalTransform.x);
        dst.y = static_cast<int>(globalTransform.y);
        dst.w = static_cast<int>(rect.w * globalTransform.scale);
        dst.h = static_cast<int>(rect.h * globalTransform.scale);
        SDL_Point center{
            dst.w / 2,
            dst.h / 2
        };
        SDL_RenderCopyEx(
            renderer,
            texture,
            nullptr,
            &dst,
            globalTransform.angle * 180.0 / M_PI, // SDL usa grados
            &center,
            SDL_FLIP_NONE
        );
    }

    void Renderer::renderTexture(SDL_Texture *texture, Math::Transform &transform, SDL_Rect &source, SDL_Rect &rect) {
        SDL_Rect dst = rect;
        TransformData globalTransform = transform.getGlobal();
        dst.x = static_cast<int>(globalTransform.x);
        dst.y = static_cast<int>(globalTransform.y);
        dst.w = static_cast<int>(rect.w * globalTransform.scale);
        dst.h = static_cast<int>(rect.h * globalTransform.scale);
        SDL_Point center{
            dst.w / 2,
            dst.h / 2
        };
        SDL_RenderCopyEx(
            renderer,
            texture,
            &source,
            &dst,
            globalTransform.angle * 180.0 / M_PI, // SDL usa grados
            &center,
            SDL_FLIP_NONE
        );
    }

    void Renderer::generateTexture(SDL_Texture *&texture, SDL_Surface *surface) {
        if (texture) {
            SDL_DestroyTexture(texture);
        }
        texture = SDL_CreateTextureFromSurface(renderer, surface);
    }

    SDL_Texture *Renderer::generateTargetTexture(int width, int height) {
        SDL_Texture* tex = SDL_CreateTexture(
            renderer,
            SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET,
            width,
            height
        );
        SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);
        return tex;
    }

    SDL_Texture *Renderer::generateStaticTexture(int width, int height) {
        return SDL_CreateTexture(
            renderer,
            SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_STATIC,
            width,
            height
        );
    }

    SDL_Texture *Renderer::generateStreamTexture(int width, int height) {
        return SDL_CreateTexture(
            renderer,
            SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_STREAMING,
            width,
            height
        );
    }

    void Renderer::drawIn(SDL_Texture *texture) {
        SDL_SetRenderTarget(renderer, texture);
    }

    void Renderer::endDrawing() {
        SDL_SetRenderTarget(renderer, nullptr);
    }


    SDL_Renderer *Renderer::get() {
        return renderer;
    }


    void Renderer::resize(int width, int height) {
        this->width = width;
        this->height = height;
        emscripten_set_canvas_element_size("#canvas", width, height);
        SDL_SetWindowSize(window, width, height);
        SDL_RenderSetViewport(renderer, nullptr);
    }
}
