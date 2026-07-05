//
// Created by MSI on 5/07/2026.
//
#pragma once
#ifndef WASM_PROJECT_MOUSE_H
#define WASM_PROJECT_MOUSE_H

enum MouseButton
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class Mouse
{
private:
    double x, y;
    double dx, dy;
    bool down, up, move, drag;
    double deltaX, deltaY;
    MouseButton button;

private:
    void mouse_down(double _x, double _y, MouseButton _button);

    void mouse_move(double _x, double _y);

    void mosue_up(double _x, double _y, MouseButton _button);
    void wheel(double _deltaX, double _deltaY);

public:
    double get_x() { return x; }
    double get_y() { return y; }
    double get_dx() { return dx; }
    double get_dy() { return dy; }
    MouseButton get_button() { return button; }
    bool is_down() { return down; }
    bool is_up() { return up; }
    bool is_move() { return move; }
    double get_deltaX() { return deltaX; }
    double get_deltaY() { return deltaY; }

public:
    Mouse();

public:
    void capture_mouse(int event, double _x, double _y, int button_idx);
    void capture_wheel(double deltaX, double deltaY);
};

#endif //WASM_PROJECT_MOUSE_H
