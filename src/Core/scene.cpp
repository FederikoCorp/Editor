#include "scene.h"

Scene::Scene(uint width, uint height) : width(width), height(height)
{
    gameObjects.resize(width);
    for(unsigned int i = 0; i < gameObjects.size(); ++i)
        gameObjects[i].resize(height);
}

void Scene::addGameObject(std::unique_ptr<GameObject> gameObject, uint x, uint y)
{
    gameObjects[x][y].swap(gameObject);
}

void Scene::removeGameObject(uint x, uint y)
{
    std::unique_ptr<GameObject> empty;
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
