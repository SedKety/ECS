#pragma once
#include <iostream> 
#include <vector>
#include "ECS.h"

class PhysicsSystem {
public:
    void UpdatePosition(std::vector<Entity>& entities);
}; 