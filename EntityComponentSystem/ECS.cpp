#include "ECS.h"

Entity& ECS::CreateEntity(int id) {
    entities.emplace_back(id);          
    return entities.back();             
}

