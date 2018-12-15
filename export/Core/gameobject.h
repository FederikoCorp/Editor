#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <vector>
#include <memory>

class SceneObject;
class Property;

class GameObject
{
public:
    using uint = unsigned int;
    using SceneObjectPtr = std::shared_ptr<SceneObject>;
    using GameObjectPtr = std::unique_ptr<GameObject>;
    using PropertyPtr = std::unique_ptr<Property>;

    GameObject(const std::string &name, SceneObjectPtr sceneObject);
    GameObject(const std::string &name, SceneObjectPtr sceneObject, uint limit);
    GameObject(const GameObject &) = delete;
    GameObject &operator= (const GameObject &) = delete;
    ~GameObject();

    void addProperty(PropertyPtr property);
    Property *getProperty(uint index);
    uint getCountProperty() const;
    SceneObjectPtr getSceneObject();
    GameObjectPtr clone();
    std::string getName() const;
    uint getX() const;
    uint getY() const;
    void setPosition(uint x, uint y);

private:
    struct GameObjectData;
    std::unique_ptr<GameObjectData> data;
};

#endif // GAMEOBJECT_H
