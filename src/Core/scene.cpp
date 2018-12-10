#include "scene.h"

Scene::Scene(uint width, uint height) : width(width), height(height)
{
    gameObjects.resize(width);
    for(unsigned int i = 0; i < gameObjects.size(); ++i)
        gameObjects[i].resize(height);
}

void Scene::addGameObject(std::unique_ptr<GameObject> gameObject, uint x, uint y)
{ 
    pair pos = std::make_pair(x, y);
    gameObjectPositionMap.insert(std::make_pair(gameObject.get(), pos));
    gameObjects[x][y].swap(gameObject);
}

void Scene::removeGameObject(uint x, uint y)
{
    std::unique_ptr<GameObject> empty;
    auto it = gameObjectPositionMap.find(gameObjects[x][y].get());
    gameObjectPositionMap.erase(it);
    gameObjects[x][y].swap(empty);
}

bool Scene::isGameObject(uint x, uint y)
{
    return gameObjects[x][y] != nullptr;
}

GameObject *Scene::getGameObject(uint x, uint y)
{
    return gameObjects[x][y].get();
}

uint Scene::getWidth() const
{
    return width;
}

uint Scene::getHeight() const
{
    return height;
}

bool Scene::isLimit(GameObject *gameObject) const
{
    SceneObject *sceneObject = gameObject->getSceneObject().get();
    return limitGameObject.find(sceneObject) != limitGameObject.end();
}

uint Scene::getLimit(GameObject *gameObject) const
{
    SceneObject *sceneObject = gameObject->getSceneObject().get();
    return limitGameObject.at(sceneObject);
}

void Scene::incLimit(GameObject *gameObject)
{
    SceneObject *sceneObject = gameObject->getSceneObject().get();
    limitGameObject[sceneObject] += 1;
}

void Scene::decLimit(GameObject *gameObject)
{
    SceneObject *sceneObject = gameObject->getSceneObject().get();
    limitGameObject[sceneObject] -= 1;
}

void Scene::setLimitGameObject(const std::unordered_map<SceneObject *, uint> &value)
{
    limitGameObject = value;
}

std::unordered_map<GameObject*, Scene::pair> &Scene::getGameObjectPositionMap()
{
    return gameObjectPositionMap;
}
