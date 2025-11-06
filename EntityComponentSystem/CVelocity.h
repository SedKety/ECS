#pragma once
#include "Vector3.h"
#include "Component.cpp"
struct CVelocity : Component {
    Vector3 velocity;
    CVelocity(Vector3 vel) : velocity(vel) {}
};