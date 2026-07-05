//
// Created by MSI on 5/07/2026.
//

#include "Mouse.h"
void Mouse::mouse_down(double _x, double _y, MouseButton _button)
{
    x = _x;
    y = _y;
    down = true;
    up = false;
    move = false;
    drag = false;
    button = _button;
}

void Mouse::mouse_move(double _x, double _y)
{
    dx = _x - x;
    dy = _y - y;
    x = _x;
    y = _y;
    move = true;
    if (down && dx != 0 && dy != 0)
        drag = true;
    else
        drag = false;
}

void Mouse::mosue_up(double _x, double _y, MouseButton _button)
{
    button = _button;
    down = false;
    up = true;
    move = false;
    drag = false;
}

void Mouse::wheel(double _deltaX, double _deltaY)
{
    deltaX = _deltaX;
    deltaY = _deltaY;
}

Mouse::Mouse()
{
}

void Mouse::capture_mouse(int event, double _x, double _y, int button_idx)
{
    MouseButton button;
    if (button_idx == 0)
        button = MouseButton::LEFT;
    if (button_idx == 1)
        button = MouseButton::MIDDLE;
    if (button_idx == 2)
        button = MouseButton::RIGHT;

    if (event == 0)
    {
        mouse_down(_x, _y, button);
    }
    if (event == 1)
    {
        mouse_move(_x, _y);
    }
    if (event == 2)
    {
        mosue_up(_x, _y, button);
    }
}

void Mouse::capture_wheel(double deltaX, double deltaY)
{
    wheel(deltaX, deltaY);
}
