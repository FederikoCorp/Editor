#ifndef SCENE_H
#define SCENE_H

#include "gameobject.h"

class Scene
{
public:
    Scene(uint width, uint height);
    void addGameObject(std::unique_ptr<GameObject> gameObject, uint x, uint y);
    void removeGameObject(uint x, uint y);
    bool isGameObject(uint x, uint y);
    GameObject *getGameObject(uint x, uint y);
    uint getWidth() const;
    uint getHeight() const;

private:
    uint width;
    uint height;
    std::vector<std::vector<std::unique_ptr<GameObject>>> gameObjects;
};

#endif // SCENE_H
