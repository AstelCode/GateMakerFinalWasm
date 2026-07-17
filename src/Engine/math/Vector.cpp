//
// Created by MSI on 8/07/2026.
//
#include <cmath>
#include "Vector.h"

#include <vector>
using namespace Engine::Math;
Vector::Vector(double x, double y) {
    this->x = x;
    this->y = y;
}

Vector::Vector() {
    this->x = 0;
    this->y = 0;
}

Vector::Vector(double s) {
    this->x = s;
    this->y = s;
}

Vector::Vector(const Vector &v) {
    this->x = v.x;
    this->y = v.y;
}

void Vector::set(double x, double y) {
    this->x = x;
    this->y = y;
}

double Vector::length() {
    return sqrt(x * x + y * y);
}

double Vector::dot(Vector &v) {
    return x * v.x + y * v.y;
}

double Vector::cross(Vector &v) {
    return x * v.y - y * v.x;
}

std::unique_ptr<Vector> Vector::normalize() {
    double l = this->length();
    return std::make_unique<Vector>(x / l, y / l);
}


std::unique_ptr<Vector> Vector::clone() const {
    return std::make_unique<Vector>(*this);
}


Vector &Vector::operator+=(Vector &v) {
    this->x += v.x;
    this->y += v.y;
    return *this;
}

Vector &Vector::operator+=(double s) {
    this->x += s;
    this->y += s;
    return *this;
}

Vector &Vector::add(double x, double y) {
    this->x += x;
    this->y += y;
    return *this;
}

Vector &Vector::operator-=(Vector &v) {
    this->x -= v.x;
    this->y -= v.y;
    return *this;
}

Vector &Vector::operator-=(double s) {
    this->x -= s;
    this->y -= s;
    return *this;
}

Vector &Vector::sub(double x, double y) {
    this->x -= x;
    this->y -= y;
    return *this;
}

Vector &Vector::operator/=(Vector &v) {
    this->x /= v.x;
    this->y /= v.y;
    return *this;
}

Vector &Vector::operator/=(double s) {
    this->x /= s;
    this->y /= s;
    return *this;
}

Vector &Vector::div(double x, double y) {
    this->x /= x;
    this->y /= y;
    return *this;
}

Vector &Vector::operator*=(Vector &v) {
    this->x *= v.x;
    this->y *= v.y;
    return *this;
}

Vector &Vector::operator*=(double s) {
    this->x *= s;
    this->y *= s;
    return *this;
}

Vector &Vector::mul(double x, double y) {
    this->x *= x;
    this->y *= y;
    return *this;
}
