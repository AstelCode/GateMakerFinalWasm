//
// Created by MSI on 8/07/2026.
//

#ifndef WASM_PROJECT_VECTOR_H
#define WASM_PROJECT_VECTOR_H

class Vector {
public:
    double x, y;
    Vector(double x, double y);

    Vector();

    Vector(double s);

    Vector(const Vector &v);

    void set_x(double x);

    void set_y(double y);

    void set(double x, double y);

    double length();

    double dot(const Vector &v);

    double cross(const Vector &v);

    Vector &operator+(const Vector &v);

    Vector &operator+(double s);

    Vector &add(double x, double y);

    Vector &operator-(const Vector &v);

    Vector &operator-(double s);

    Vector &sub(double x, double y);

    Vector &operator/(const Vector &v);

    Vector &operator/(double s);

    Vector &div(double x, double y);

    Vector &operator*(const Vector &v);

    Vector &operator*(double s);

    Vector &mul(double x, double y);

    Vector *clone() const;

    Vector *normalize();
};


#endif //WASM_PROJECT_VECTOR_H
