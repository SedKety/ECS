#include <iostream>
#include <vector>
#include <typeinfo>
#include "ECS.h"

//Supposed to imitate the "OnFrame" or "Update" methods. However patrick will call it lols
void FramePlaceHolder() {
	for (int i = 0; i < 100'000'000; ++i) {
		volatile int temp = i * i; // Prevent optimization
	}
}

int main() {
	ECS ecs = ECS();

	for (int i = 0; i < 1000; ++i) {
		auto id = i;

		Vector3 pos(0, 0, i);
		Quaternion rot(0.0f, 0.0f, 0.0f, 1.0f);
		Vector3 scale(1.0f, 1.0f, 1.0f);

		auto entity = ecs.CreateEntity(id);
		entity->AddComponent<CTransform>(pos, rot, scale);
		entity->AddComponent<CVelocity>(Vector3(0.0f, 0.0f, 0.0f));
	}
	std::cout << "Entities created: " << ecs.entities.size() << std::endl;

	for (int i = 0; i < ecs.entities.size(); ++i) {
		auto components = ecs.entities[i].GetAllComponents();
	}

	PhysicsSystem physicsSystem = PhysicsSystem();
	physicsSystem.UpdatePosition(ecs.entities);

	while (true) {
		FramePlaceHolder();
		physicsSystem.UpdatePosition(ecs.entities);
	}
	return 0;
}
