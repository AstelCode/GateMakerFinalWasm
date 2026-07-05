//
// Created by MSI on 5/07/2026.
//

#pragma once
#ifndef WASM_PROJECT_CANVAS2D_H
#define WASM_PROJECT_CANVAS2D_H

#include "emscripten/val.h"
using namespace emscripten;

enum class TextAlign
{
    Left,
    Right,
    Center,
    Start,
    End
};

enum class TextBaseLine
{
    Top,
    Hanging,
    Middle,
    Alphabetic,
    Ideographic,
    Bottom
};

inline std::string toString(TextAlign align)
{
    switch (align)
    {
    case TextAlign::Left:
        return "left";
    case TextAlign::Right:
        return "right";
    case TextAlign::Center:
        return "center";
    case TextAlign::Start:
        return "start";
    case TextAlign::End:
        return "end";
    }
    return "left";
}

inline std::string toString(TextBaseLine baseline)
{
    switch (baseline)
    {
    case TextBaseLine::Top:
        return "top";

    case TextBaseLine::Hanging:
        return "hanging";

    case TextBaseLine::Middle:
        return "middle";

    case TextBaseLine::Alphabetic:
        return "alphabetic";

    case TextBaseLine::Ideographic:
        return "ideographic";

    case TextBaseLine::Bottom:
        return "bottom";
    }

    return "alphabetic";
}
class Canvas2D
{
private:
    val ctx;

public:
    Canvas2D(val canvas);
    void fillRect(int x, int y, int w, int h);
    void drawFPS(int fps);
    void textAlign(TextAlign textAlign, TextBaseLine baseLine);
    void drawText(std::string text, int x, int y);
    void textFont(std::string font);
    void clear();
};

#endif //WASM_PROJECT_CANVAS2D_H
