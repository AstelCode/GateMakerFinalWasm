//
// Created by MSI on 8/07/2026.
//

#ifndef WASM_PROJECT_TRANSFORM_H
#define WASM_PROJECT_TRANSFORM_H
#include <memory>
#include <vector>

#include "Matrix3x3.h"
#include "TransformData.h"

namespace Engine::Math {
    using namespace std;
    class Transform : public std::enable_shared_from_this<Transform> {
    public:
        Transform();

        TransformData getLocalTransform();

        TransformData getGlobal();

        void destroy();

        void addChild(Transform *child);


        void updateChildren();

        void updated();

        Matrix3x3 localMatrix;

    private:
        shared_ptr<Transform> parent = nullptr;
        vector<shared_ptr<Transform> > children;

        Matrix3x3 globalMatrix;


        static long current_id;
        int id;
        bool is_updated;
    };
}


#endif //WASM_PROJECT_TRANSFORM_H
