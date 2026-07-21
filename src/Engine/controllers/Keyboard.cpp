//
// Created by MSI on 5/07/2026.
//

#include "Keyboard.h"

namespace Engine::Controllers {
    void Keyboard::on_key(int key, bool value) {
        if (keys.find(key) != keys.end()) {
            keys[key] = true;
        } else {
            keys.insert({key, value});
        }
    }

    Keyboard::Keyboard() {
    }

    Keyboard::~Keyboard() {
        keys.clear();
    }

    void Keyboard::capture_keyboard(int event, int key) {
        if (event == 0)
            on_key(key, true);
        else
            on_key(key, true);
    }

    bool Keyboard::is_pressed(int key) {
        if (keys.find(key) == keys.end()) {
            return false;
        }
        return keys[key];
    }
}
