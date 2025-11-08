#include "ECS.h"

Entity* ECS::CreateEntity(int id) {
    entities.emplace_back(id);          
    return &entities.back();             
}
Entity* ECS::GetEntity(int id) {
	for (auto& entity : entities) {
		if (entity.id == id) {
			return &entity;
		}
	}
	throw std::runtime_error("Entity not found");
}

