#pragma once
#include "Vector3.h"
#include "Component.h"

struct CTransform : Component {
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
    CTransform(Vector3 pos, Vector3 rot, Vector3 size)
        : position(pos), rotation(rot), scale(size) {
    }
};