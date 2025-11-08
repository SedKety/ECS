#pragma once
#include "DataTypes.h"
#include "Component.h"

struct CTransform : Component {
    Vector3 position;
	Quaternion rotation;
    Vector3 scale;
    CTransform(Vector3 pos, Quaternion rot, Vector3 size)
        : position(pos), rotation(rot), scale(size) {
    }
};