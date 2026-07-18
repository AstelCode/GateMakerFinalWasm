//
// Created by MSI on 17/07/2026.
//

#ifndef WASM_PROJECT_MATRIX3X3_H
#define WASM_PROJECT_MATRIX3X3_H

#include <math.h>

#include "TransformData.h"
#include "Vector.h"
using namespace std;
namespace Engine::Math {
    class Matrix3x3 {
    public:
        Matrix3x3();
        void setTransform(double scale, double rotation, double x, double y);

        Matrix3x3 operator*(Matrix3x3 matrix);

        Vector operator*(Vector vector);
        Vector mul(Vector vector, double z );
        TransformData toTransform();


    private:
        double data[9];
    };
}


#endif //WASM_PROJECT_MATRIX3X3_H
