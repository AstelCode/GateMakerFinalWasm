//
// Created by MSI on 5/07/2026.
//

#include "Mouse.h"

#include <SDL_mouse.h>

namespace Engine::Controllers {
    void Mouse::mouse_down(long _x, long _y, int btn_idx) {
        _x = _x;
        _y = _y;
        _down = true;
        _up = false;
        _move = false;
        _drag = false;

        _button = mapButton(btn_idx);
    }

    void Mouse::mouse_move(long _x, long _y) {
        this->_dx = _x - this->_x;
        this->_dy = _y - this->_y;
        this->_x = _x;
        this->_y = _y;
        _move = true;
        if (_down && _dx != 0 && _dy != 0)
            _drag = true;
        else
            _drag = false;
    }

    void Mouse::mouse_up(long _x, long _y, int btn_idx) {
        _button = mapButton(btn_idx);
        _down = false;
        _up = true;
        _move = false;
        _drag = false;
        _button = mapButton(btn_idx);
    }

    void Mouse::wheel(long _deltaX, long _deltaY) {
        this->_deltaX = _deltaX;
        this->_deltaY = _deltaY;
    }

    Mouse::Mouse() {
    }

    MouseButton Mouse::mapButton(int idx) {
        switch (idx) {
            case SDL_BUTTON_LEFT: return MouseButton::LEFT;
            case SDL_BUTTON_MIDDLE: return MouseButton::MIDDLE;
            case SDL_BUTTON_RIGHT: return MouseButton::RIGHT;
            default: return MouseButton::LEFT;
        }
    }
}
