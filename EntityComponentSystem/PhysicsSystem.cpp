#include "PhysicsSystem.h"
#include "CTransform.h"
#include "Entity.h" 
#include <iostream>

void PhysicsSystem::UpdatePosition(std::vector<Entity>& entities) {
    for (auto& entity : entities) {
        if (auto* transform = entity.GetComponent<CTransform>()) {
            transform->position.x += 1.0f;
            std::cout << "Updated Entity " << entity.id
                << " to x=" << transform->position.x << "\n";
        }
    }
}
