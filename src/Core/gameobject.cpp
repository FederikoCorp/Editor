#include <limits>
#include "../../export/Core/gameobject.h"
#include "../../export/Core/Property/property.h"

struct GameObject::GameObjectData
{
    std::string name;
    std::shared_ptr<SceneObject> sceneObject;
    std::vector<std::unique_ptr<Property>> properties;
    uint x;
    uint y;
    uint limit = std::numeric_limits<uint>::max();
    std::shared_ptr<uint> count;
};

GameObject::GameObject(const std::string &name, GameObject::SceneObjectPtr sceneObject) :
    data(new GameObjectData)
{
    data->name = name;
    data->sceneObject = sceneObject;
    data->count = std::make_shared<uint>(1);
}

GameObject::GameObject(const std::string &name, SceneObjectPtr sceneObject, uint limit) :
    data(new GameObjectData)
{
    data->name = name;
    data->sceneObject = sceneObject;
    data->count = std::make_shared<uint>(1);
    data->limit = limit;
}

GameObject::~GameObject()
{
    *data->count = *data->count - 1;
}

void GameObject::addProperty(PropertyPtr property)
{
    data->properties.emplace_back(property.release());
}

Property *GameObject::getProperty(uint index)
{
    return data->properties.at(index).get();
}

GameObject::uint GameObject::getCountProperty() const
{
    return data->properties.size();
}

GameObject::SceneObjectPtr GameObject::getSceneObject()
{
    return data->sceneObject;
}

GameObject::GameObjectPtr GameObject::clone()
{
    if(*data->count >= data->limit)
        return nullptr;

    std::unique_ptr<GameObject> copy(new GameObject(data->name, data->sceneObject, data->limit));
    copy->data->count = data->count;
    *data->count = *data->count + 1;
    for(PropertyPtr &property : data->properties)
        copy->addProperty(property->clone());
    return copy;
}

std::string GameObject::getName() const
{
    return data->name;
}

GameObject::uint GameObject::getX() const
{
    return data->x;
}

GameObject::uint GameObject::getY() const
{
    return data->y;
}

void GameObject::setPosition(GameObject::uint x, GameObject::uint y)
{
    data->x = x;
    data->y = y;
}

