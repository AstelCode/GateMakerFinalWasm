//
// Created by MSI on 17/07/2026.
//

#include "Matrix3x3.h"

namespace Engine::Math {
    Matrix3x3::Matrix3x3() {
        data[0] = 1;
        data[1] = 0;
        data[2] = 0;
        data[3] = 0;
        data[4] = 1;
        data[5] = 0;
        data[6] = 0;
        data[7] = 0;
        data[8] = 1;
    }

    void Matrix3x3::setTransform(double scale, double rotation, double x, double y) {
        data[0] = cos(rotation) * scale;
        data[1] = -sin(rotation) * scale;
        data[2] = x;
        data[3] = -data[1];
        data[4] = data[0];
        data[5] = y;
    }

    Matrix3x3 Matrix3x3::operator*(Matrix3x3 matrix) {
        Matrix3x3 result;

        result.data[0] = data[0] * matrix.data[0] + data[1] * matrix.data[3] + data[2] * matrix.data[6];
        result.data[1] = data[0] * matrix.data[1] + data[1] * matrix.data[4] + data[2] * matrix.data[7];
        result.data[2] = data[0] * matrix.data[2] + data[1] * matrix.data[5] + data[2] * matrix.data[8];

        result.data[3] = data[3] * matrix.data[0] + data[4] * matrix.data[3] + data[5] * matrix.data[6];
        result.data[4] = data[3] * matrix.data[1] + data[4] * matrix.data[4] + data[5] * matrix.data[7];
        result.data[5] = data[3] * matrix.data[2] + data[4] * matrix.data[5] + data[5] * matrix.data[8];

        result.data[6] = data[6] * matrix.data[0] + data[7] * matrix.data[3] + data[8] * matrix.data[6];
        result.data[7] = data[6] * matrix.data[1] + data[7] * matrix.data[4] + data[8] * matrix.data[7];
        result.data[8] = data[6] * matrix.data[2] + data[7] * matrix.data[5] + data[8] * matrix.data[8];

        return result;
    }

    Vector Matrix3x3::operator*(Vector vector) {
        Vector result;
        result.x = data[0] * vector.x + data[1] * vector.y + data[2] * 1;
        result.y = data[3] * vector.x + data[4] * vector.y + data[5] * 1;
        return result;
    }

    Vector Matrix3x3::mul(Vector vector, double z) {
        Vector result;
        result.x = data[0] * vector.x + data[1] * vector.y + data[2] * z;
        result.y = data[3] * vector.x + data[4] * vector.y + data[5] * z;
        return result;
    }

    TransformData Matrix3x3::toTransform() {
        TransformData result;
        result.x = data[2];
        result.y = data[5];
        result.scale = std::sqrt(data[0] * data[0] + data[1] * data[1]);
        result.angle = std::atan2(data[3], data[0]);

        return result;
    }
}
