#include <iostream>
#include <vector>
#include <typeinfo>

// Vector3, representing a 3D point in space
struct Vector3 {
    float x, y, z;
};

// Base component class
struct Component {
    virtual ~Component() = default;
};

// Transform component
struct CTransform : Component {
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
    CTransform(Vector3 pos, Vector3 rot, Vector3 size)
        : position(pos), rotation(rot), scale(size) {
    }
};

// Velocity component
struct CVelocity : Component {
    Vector3 velocity;
    CVelocity(Vector3 vel) : velocity(vel) {}
};

// Entity class
struct Entity {
    int id;
    std::vector<Component*> components;

    Entity(int id, const std::vector<Component*>& initialComponents)
        : id(id), components(initialComponents) {
    }

    // Generic GetComponent function
    template<typename T>
    T* GetComponent() {
        for (auto* comp : components) {
            if (auto* desired = dynamic_cast<T*>(comp)) {
                return desired;
            }
        }
        return nullptr; // not found
    }
};

// Physics system class, manages entities and their physics-related components
class PhysicsSystem {
public:
    std::vector<Entity> entities;

    void DebugInformation() {
        for (auto& entity : entities) {
            std::cout << "Entity ID: " << entity.id << std::endl;

            if (auto* transform = entity.GetComponent<CTransform>()) {
                std::cout << "Initial Position: ("
                    << transform->position.x << ", "
                    << transform->position.y << ", "
                    << transform->position.z << ")" << std::endl;
            }
            else {
                std::cout << "No Transform component found.\n";
            }
        }
    }

    void UpdatePosition() {
        for (auto& entity : entities) {
            if (auto* transform = entity.GetComponent<CTransform>()) {
                std::cout << "Updating Position for Entity ID: " << entity.id << std::endl;
                transform->position.x += 1.0f;
                std::cout << "New Position: ("
                    << transform->position.x << ", "
                    << transform->position.y << ", "
                    << transform->position.z << ")" << std::endl;
            }
        }
    }
};

int main() {
    std::vector<Entity> entities;
    for (int i = 0; i < 5; ++i) {
        Vector3 transformInformation = { float(i * 10), float(i * 5), 0.0f };
        CTransform* transform = new CTransform(transformInformation, transformInformation, transformInformation);

        std::vector<Component*> initialComponents = { transform };
        Entity entity(i, initialComponents);
        entities.push_back(entity);
    }

    PhysicsSystem physicsSystem;
    physicsSystem.entities = entities;

    physicsSystem.DebugInformation();
    physicsSystem.UpdatePosition();

    return 0;
}
