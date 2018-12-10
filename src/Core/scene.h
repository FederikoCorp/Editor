#ifndef SCENE_H
#define SCENE_H

#include "gameobject.h"

class Scene
{
public:
    using pair = std::pair<uint, uint>;

    Scene(uint width, uint height);
    void addGameObject(std::unique_ptr<GameObject> gameObject, uint x, uint y);
    void removeGameObject(uint x, uint y);
    bool isGameObject(uint x, uint y);
    GameObject *getGameObject(uint x, uint y);
    uint getCountGameObject() const;
    uint getWidth() const;
    uint getHeight() const;

    bool isLimit(GameObject *gameObject) const;
    uint getLimit(GameObject *gameObject) const;
    void incLimit(GameObject *gameObject);
    void decLimit(GameObject *gameObject);
    void setLimitGameObject(const std::unordered_map<SceneObject *, uint> &value);

    std::unordered_map<GameObject *, pair>& getGameObjectPositionMap() ;

private:
    uint width;
    uint height;

    std::unordered_map<GameObject *, pair> gameObjectPositionMap;
    std::vector<std::vector<std::unique_ptr<GameObject>>> gameObjects;

    //SceneObject используется потому, что он у GameObject общий и по нему, можно найти количество доступных объектов
    //другой вариант, использовать id у объекта
    std::unordered_map<SceneObject*, uint> limitGameObject;
};

#endif // SCENE_H
