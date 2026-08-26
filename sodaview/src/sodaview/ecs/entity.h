#include <memory>
#include <vector>
#include "components.h"

class Entity
{
    private:
        std::vector<std::unique_ptr<Component>> components;

    public:
        template<typename T, typename... Args>
        T* AddComponent(Args&& )
}