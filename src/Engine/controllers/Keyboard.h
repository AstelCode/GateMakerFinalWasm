//
// Created by MSI on 5/07/2026.
//
#pragma once

#ifndef WASM_PROJECT_KEYBOARD_H
#define WASM_PROJECT_KEYBOARD_H
#include <map>
using namespace std;

namespace Engine::Controllers {
    class Keyboard
    {
    private:
        map<char, bool> keys;

    private:
        void on_key(int key, bool value);

    public:
        Keyboard();
        ~Keyboard();
        void capture_keyboard(int event, int key);
        bool is_pressed(int key);
    };
}


#endif //WASM_PROJECT_KEYBOARD_H
