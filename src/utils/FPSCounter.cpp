//
// Created by MSI on 5/07/2026.
//

#include "FPSCounter.h"

void FPSCounter::update() {
    auto current = Clock::now();

    counter++;

    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(
        current - prevTime);

    if (elapsed.count() >= 1) {
        fps = counter;
        counter = 0;
        prevTime = current;
    }
}

int FPSCounter::getFPS() const {
    return fps;
}
