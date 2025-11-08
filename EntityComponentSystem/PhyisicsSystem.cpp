#include "PhysicsSystem.h"
#include "CTransform.h"
#include "Entity.h" 
#include <iostream>

void PhysicsSystem::UpdatePosition(std::vector<Entity>& entities) {
    for (auto& entity : entities) {
        if (auto* transform = entity.GetComponent<CTransform>()) {
			if (auto* velocity = entity.GetComponent<CVelocity>()) {
				transform->position.x += velocity->velocity.x;
				transform->position.y += velocity->velocity.y;
				transform->position.z += velocity->velocity.z;
				std::cout << "Entity: " << entity.id << " is at position: (" << transform->position.x << ", "
					<< transform->position.y << ", "
					<< transform->position.z << ")\n";
			}
        }
    }
} 
