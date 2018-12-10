#include "gameobject.h"

GameObject::GameObject(const std::string &name, std::shared_ptr<SceneObject> sceneObject) :
    name(name), sceneObject(sceneObject)
{

}

void GameObject::addProperty(std::unique_ptr<Property> property)
{
    vecProperty.emplace_back(property.release());
}

Property *GameObject::getProperty(uint index)
{
    return vecProperty.at(index).get();
}

uint GameObject::getCountProperty() const
{
    return vecProperty.size();
}

std::shared_ptr<SceneObject> GameObject::getSceneObject()
{
    return sceneObject;
}

std::unique_ptr<GameObject> GameObject::clone()
{
    std::unique_ptr<GameObject> copy(new GameObject(name, sceneObject));
    for(std::unique_ptr<Property> &property : vecProperty)
        copy->addProperty(property->clone());
    return copy;
}

std::string GameObject::getName() const
{
    return name;
}
