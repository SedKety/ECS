#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Component.h"
#include "ECS.h"

struct Entity {
    int id;
    std::vector<Component*> components;

    Entity(int id) : id(id) {} //Constructor, takes id as EVERY entity MUST have an id
    //Deconstructor
    ~Entity() {
        components.clear(); //Delete all the components to prevent memory leakings
		components.shrink_to_fit(); // Free unused memory
    }

public:
    template<typename T, typename... Args>
    void AddComponent(Args&&... args) {
        T* comp = new T(std::forward<Args>(args)...);
        components.push_back(comp);
    }

    template<typename T>
    T* GetComponent() {
        for (auto* comp : components) {
            if (auto* desired = dynamic_cast<T*>(comp)) {
                return desired;
            }
        }
        return nullptr;
    }
    
	template<typename T>
    const bool HasComponentOfType() const {
		for (const auto* comp : components) {
			if (dynamic_cast<const T*>(comp)) {
				return true;
			}
		}
		return false;
	}

	std::vector<Component*> GetAllComponents() {
		return components;
	}

};
