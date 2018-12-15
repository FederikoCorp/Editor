#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <map>

class GameObject;
class SceneObject;

class Scene
{
public:
    using uint = unsigned int;
    using Position = std::pair<uint, uint>;
    using GameObjectPtr = std::unique_ptr<GameObject>;
    using Iterator = std::map<Position, GameObjectPtr>::const_iterator;

    Scene(uint width, uint height);
    ~Scene();

    void addGameObject(GameObjectPtr gameObject);
    void removeGameObject(uint x, uint y);
    bool isGameObject(uint x, uint y);
    GameObject *getGameObject(uint x, uint y);
    uint getWidth() const;
    uint getHeight() const;
    Iterator begin();
    Iterator end();

private:
    struct SceneData;
    std::unique_ptr<SceneData> data;
};

#endif // SCENE_H
