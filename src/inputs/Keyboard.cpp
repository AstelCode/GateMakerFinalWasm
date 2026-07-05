//
// Created by MSI on 5/07/2026.
//

#include "Keyboard.h"
void Keyboard::on_key(char key, bool value)
{
    if (keys.find(key) != keys.end())
    {
        keys[key] = true;
    }
    else
    {
        keys.insert({key, value});
    }
}

Keyboard::Keyboard()
{
}

Keyboard::~Keyboard()
{
    keys.clear();
}

void Keyboard::capture_keyboard(string event, char key)
{
    if (event == "down")
        on_key(key, true);
    else
        on_key(key, true);
}

bool Keyboard::is_pressed(char key)
{
    if (keys.find(key) == keys.end())
    {
        return false;
    }
    return keys[key];
}
