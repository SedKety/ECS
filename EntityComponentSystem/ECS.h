#pragma once
#include <vector>
#include "DataTypes.h"	

//Entity
#include "Entity.h"	

//Components
#include "Component.h" //Root Component
#include "CTransform.h"
#include "CVelocity.h"

//Systems
#include "PhysicsSystem.h"


//ECS
struct ECS {
	std::vector<Entity> entities;
	Entity* CreateEntity(int id);
	Entity* GetEntity(int id);
}; 