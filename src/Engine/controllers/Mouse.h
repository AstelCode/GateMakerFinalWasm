//
// Created by MSI on 5/07/2026.
//
#pragma once
#ifndef WASM_PROJECT_MOUSE_H
#define WASM_PROJECT_MOUSE_H

namespace Engine::Controllers {
    enum MouseButton {
        LEFT = 0,
        MIDDLE = 1,
        RIGHT = 2
    };

    class Mouse {
    private:
        long _x, _y;
        long _dx, _dy;
        bool _down, _up, _move, _drag;
        long _deltaX, _deltaY;
        MouseButton _button;

    public:
        void mouse_down(long _x, long _y, int btn_idx);

        void mouse_move(long _x, long _y);

        void mouse_up(long _x, long _y, int btn_idx);

        void wheel(long _deltaX, long _deltaY);

    public:
        long x() { return _x; }
        long y() { return _y; }
        long dx() { return _dx; }
        long dy() { return _dy; }
        MouseButton button() { return _button; }
        bool is_down() { return _down; }
        bool is_up() { return _up; }
        bool is_move() { return _move; }
        long deltaX() { return _deltaX; }
        long deltaY() { return _deltaY; }

    public:
        Mouse();

        MouseButton mapButton(int idx);

    public:
        // void capture_mouse(int idx, long _x, long _y, MouseButton button);

        // void capture_wheel(long deltaX, long deltaY);
    };
}


#endif //WASM_PROJECT_MOUSE_H
