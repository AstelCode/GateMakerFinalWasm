//
// Created by MSI on 8/07/2026.
//

#ifndef WASM_PROJECT_VECTOR_H
#define WASM_PROJECT_VECTOR_H
#include <memory>

namespace Engine::Math {
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

        double dot(Vector &v);

        double cross(Vector &v);

        Vector &operator+=(Vector &v);

        Vector &operator+=(double s);

        Vector &add(double x, double y);

        Vector &operator-=(Vector &v);

        Vector &operator-=(double s);

        Vector &sub(double x, double y);

        Vector &operator/=(Vector &v);

        Vector &operator/=(double s);

        Vector &div(double x, double y);

        Vector &operator*=(Vector &v);

        Vector &operator*=(double s);

        Vector &mul(double x, double y);

        std::unique_ptr<Vector> clone() const;

        std::unique_ptr<Vector> normalize();
    };
}

#endif //WASM_PROJECT_VECTOR_H
