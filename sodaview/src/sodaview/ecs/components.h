// an example and skeleton of a component system


// component base class
class Component
{
    public:
        virtual ~Component() = default;
        virtual void Update(float deltaTime) {}
};

// specific component types
class TransformComponent : public Component
{
    private:
        glm::vec3 position;
        glm::quat rotation;
        glm::vec3 scale;

    public:
        // methods to manipulate transforms
};

class MeshComponent : public Component
{
    private:
        Mesh* mesh;
        Material* material;

    public:
        // methods to render the mesh
}

