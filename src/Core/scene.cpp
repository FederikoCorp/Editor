#include <map>
#include "../../export/Core/scene.h"
#include "../../export/Core/gameobject.h"

struct Scene::SceneData
{
    uint width;
    uint height;
    std::map<Position, GameObjectPtr> gameObjects;
};

Scene::Scene(uint width, uint height) : data(new SceneData())
{
    data->width = width;
    data->height = height;
}

Scene::~Scene() = default;

void Scene::addGameObject(GameObjectPtr gameObject)
{ 
    Position pos = std::make_pair(gameObject->getX(), gameObject->getY());
    data->gameObjects.insert(std::make_pair(pos, std::move(gameObject)));
}

void Scene::removeGameObject(uint x, uint y)
{
    auto it = data->gameObjects.find(std::make_pair(x, y));
    data->gameObjects.erase(it);
}

bool Scene::isGameObject(uint x, uint y)
{
    return data->gameObjects.find(std::make_pair(x, y)) != data->gameObjects.end();
}

GameObject *Scene::getGameObject(uint x, uint y)
{
    auto it = data->gameObjects.find(std::make_pair(x, y));
    if(it == data->gameObjects.end())
        return nullptr;
    return it->second.get();
}

Scene::uint Scene::getWidth() const
{
    return data->width;
}

Scene::uint Scene::getHeight() const
{
    return data->height;
}

Scene::Iterator Scene::begin()
{
    return data->gameObjects.cbegin();
}

Scene::Iterator Scene::end()
{
    return data->gameObjects.cend();
}
