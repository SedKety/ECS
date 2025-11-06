#include <iostream>
#include <vector>
#include <typeinfo>
#include "ECS.h"
#include "Vector3.h"



int main() {
	ECS ecs = ECS();

	for (int i = 0; i < 5; ++i) {
		auto id = i;

		Vector3 pos(float(i * 10), float(i * 5), 0.0f);
		Vector3 scale(1.0f, 1.0f, 1.0f);

		auto entity = ecs.CreateEntity(id);
		entity.AddComponent<CTransform>(pos, pos, scale);
		entity.AddComponent<CVelocity>(Vector3(0.0f, 0.0f, 0.0f));
	}
	std::cout << "Entities created: " << ecs.entities.size() << std::endl;

	for (int i = 0; i < ecs.entities.size(); ++i) {
		auto components = ecs.entities[i].GetAllComponents();
		
	}

	PhysicsSystem physicsSystem = PhysicsSystem();
	physicsSystem.UpdatePosition(ecs.entities);

	return 0;
}
