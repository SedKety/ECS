#include "Vector3.h"
#include "Component.h"
// Velocity component
struct CVelocity : Component {
    Vector3 velocity;
    CVelocity(Vector3 vel) : velocity(vel) {}
};
