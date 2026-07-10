//
// Created by MSI on 5/07/2026.
//
#pragma once
#ifndef WASM_PROJECT_FPSCOUNTER_H
#define WASM_PROJECT_FPSCOUNTER_H


#include <chrono>

class FPSCounter
{
private:
    using Clock = std::chrono::steady_clock;

    int fps = 0;
    Clock::time_point prevTime = Clock::now();
    int counter = 0;

public:
    void update();

    int getFPS() const;
};

#endif //WASM_PROJECT_FPSCOUNTER_H
