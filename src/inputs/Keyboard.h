//
// Created by MSI on 5/07/2026.
//
#pragma once

#ifndef WASM_PROJECT_KEYBOARD_H
#define WASM_PROJECT_KEYBOARD_H



#include <map>
#include <string>
using namespace std;

class Keyboard
{
private:
    map<char, bool> keys;

private:
    void on_key(char key, bool value);

public:
    Keyboard();
    ~Keyboard();
    void capture_keyboard(string event, char key);
    bool is_pressed(char key);
};

#endif //WASM_PROJECT_KEYBOARD_H
