//
// Created by MSI on 8/07/2026.
//

#include "RectCollider.h"


RectCollider::RectCollider(double width, double height){
    this->width = width;
    this->height = height;
}
RectCollider::~RectCollider() {
    delete position;
}

bool RectCollider::pointInside(Vector &v) {
    double dx = v.x - position->x;
    double dy = v.y - position->y;
    return (
        -width / 2 <= dx && dx <= width / 2 &&
        -height / 2 <= dy && dy <= height / 2
    );
}
