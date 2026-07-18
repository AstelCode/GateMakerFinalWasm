//
// Created by MSI on 8/07/2026.
//

#include "Transform.h"
using namespace Engine::Math;

long Transform::current_id = 0;

Transform::Transform() {
    id = current_id++;
}

TransformData Transform::getLocalTransform() {
    return localMatrix.toTransform();
}

TransformData Transform::getGlobal() {
    return (globalMatrix * localMatrix).toTransform();
}

void Transform::destroy() {
    if (parent) {
        vector<shared_ptr<Transform> > &children = parent->children;
        long _id = this->id;
        children.erase(remove_if(children.begin(), children.end(), [_id](shared_ptr<Transform> child) {
            return _id == child->id;
        }), children.end());
        parent = nullptr;
        children.clear();
    }
}

void Transform::addChild(Transform *child) {
    child->parent = shared_from_this();
    children.push_back(child->shared_from_this());
}

void Transform::updateChildren() {
    Matrix3x3 _globalMatrix;

    if (!is_updated) return;
    if (parent != nullptr) {
        _globalMatrix = parent->globalMatrix * localMatrix;
    }else {
        _globalMatrix = localMatrix;
    }
    for (auto &child: children) {
        if (parent != nullptr) {
            child->globalMatrix = _globalMatrix;
            updateChildren();
        }
    }

    is_updated = false;
}

void Transform::updated() {
    is_updated = true;
}
