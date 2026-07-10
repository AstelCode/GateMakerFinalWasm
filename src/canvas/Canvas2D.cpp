//
// Created by MSI on 5/07/2026.
//

#include "Canvas2D.h"

Canvas2D::Canvas2D(val canvas) {
    ctx = canvas.call<val>("getContext", std::string("2d"));
    m_canvas = canvas;
}

Canvas2D::Canvas2D() {
    val document = val::global("document");
    m_canvas = document.call<val>("createElement", std::string("canvas"));
    ctx = m_canvas.call<val>("getContext", std::string("2d"));
}

void Canvas2D::fillRect(int x, int y, int w, int h) {
    ctx.call<void>("fillRect", x, y, w, h);
}

void Canvas2D::drawFPS(int fps) {
    std::string nombre = std::to_string(fps);
    nombre = "FPS: " + nombre;

    textFont("25px sans-serif");
    textAlign(TextAlign::Start, TextBaseLine::Top);
    drawText(nombre, 20, 20);
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

void Canvas2D::drawImage(val canvas, int x, int y, int w, int h, int sx, int sy, int sw, int sh) {
    ctx.call<void>("drawImage",
                   canvas,
                   x,
                   y,
                   w,
                   h,
                   sx,
                   sy,
                   sw,
                   sh
    );
}

void Canvas2D::drawImagen(val canvas, int x, int y, int w, int h) {
    ctx.call<void>("drawImage",
                   canvas,
                   x,
                   y,
                   w,
                   h
    );
}

void Canvas2D::clear() {
    val canvas = ctx["canvas"];
    int width = canvas["width"].as<int>();
    int height = canvas["height"].as<int>();
    ctx.call<void>("clearRect", 0, 0, width, height);
}

val Canvas2D::canvas() {
    return m_canvas;
}

void Canvas2D::setSize(int w, int h) {
    m_width = w;
    m_height = h;
    m_canvas.set("width", m_width);
    m_canvas.set("height", m_height);
}

void Canvas2D::width(int w) {
    m_width = w;
    m_canvas.set("width", m_width);
}

void Canvas2D::height(int h) {
    m_height = h;
    m_canvas.set("height", m_height);
}

int Canvas2D::width() {
    return m_width;
}

int Canvas2D::height() {
    return m_height;
}
