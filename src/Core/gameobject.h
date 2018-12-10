#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include "../../export/Core/Property/property.h"
#include "../../export/Core/SceneObject/sceneobject.h"

using uint = unsigned int;

class GameObject
{
public:
    GameObject(const std::string &name, std::shared_ptr<SceneObject> sceneObject);
    void addProperty(std::unique_ptr<Property> property);
    Property *getProperty(uint index);
    uint getCountProperty() const;
    std::shared_ptr<SceneObject> getSceneObject();
    std::unique_ptr<GameObject> clone();
    std::string getName() const;

private:
    std::string name;
    std::shared_ptr<SceneObject> sceneObject;
    std::vector<std::unique_ptr<Property>> vecProperty;
};

#endif // GAMEOBJECT_H
