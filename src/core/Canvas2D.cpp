//
// Created by MSI on 5/07/2026.
//

#include "Canvas2D.h"

Canvas2D::Canvas2D(val canvas) {
    ctx = canvas.call<val>("getContext", std::string("2d"));
}

void Canvas2D::fillRect(int x, int y, int w, int h) {
    ctx.call<void>("fillRect", x, y, w, h);
}

void Canvas2D::drawFPS(int fps) {
    std::string nombre = std::to_string(fps);
    nombre = "FPS: " + nombre;

    textFont("25px sans-serif");
    textAlign(TextAlign::Start, TextBaseLine::Top);
    drawText(nombre, 0, 0);
}

void Canvas2D::textAlign(TextAlign textAlign, TextBaseLine baseLine) {
    ctx.set("textBaseline", toString(baseLine));
    ctx.set("textAlign", toString(textAlign));
}

void Canvas2D::drawText(std::string text, int x, int y) {
    ctx.call<void>("fillText", text, x, y);
}

void Canvas2D::textFont(std::string font) {
    ctx.set("font", font);
}

void Canvas2D::clear() {
    val canvas = ctx["canvas"];
    int width = canvas["width"].as<int>();
    int height = canvas["height"].as<int>();
    ctx.call<void>("clearRect", 0, 0, width, height);
}
