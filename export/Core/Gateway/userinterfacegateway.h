#ifndef USERINTERFACEGATEWAY_H
#define USERINTERFACEGATEWAY_H

#include <functional>
#include <memory>

class PropertyBoolControl;
class PropertyFloatControl;
class PropertyIntControl;
class PropertyListStateControl;
class SceneObject;

using uint = unsigned int;

class UserInterfaceGateway
{
public:
    UserInterfaceGateway() = default;
    virtual ~UserInterfaceGateway() = default;
    virtual void exit() = 0;

    virtual PropertyBoolControl* createPropertyBoolControl() = 0;
    virtual PropertyFloatControl* createPropertyFloatControl() = 0;
    virtual PropertyIntControl* createPropertyIntControl() = 0;
    virtual PropertyListStateControl* createPropertyListStateControl() = 0;
    virtual void destroyPropertyControls() = 0;

    virtual void addSceneObject(std::shared_ptr<SceneObject> sceneObject, uint x, uint y) = 0;
    virtual void selectSceneObject(uint x, uint y) = 0;
    virtual void removeSceneObject(uint x, uint y) = 0;
    virtual void createScene(uint width, uint height) = 0;
    virtual void clearScene() = 0;

    virtual void addGameObjectTool(std::shared_ptr<SceneObject> sceneObject, const std::string &name) = 0;
    virtual void setAvailableGameObjectTool(uint index, bool available) = 0;

    virtual void setCallbackAddGameObject(const std::function<void (uint x, uint y, uint index)> &value) = 0;
    virtual void setCallbackRemoveGameObject(const std::function<void (uint x, uint y)> &value) = 0;
    virtual void setCallbackSelectGameObject(const std::function<void (uint x,uint y)> &value) = 0;
    virtual void setCallbackCreateScene(const std::function<void (uint width, uint height)> &value) = 0;
    virtual void setCallbackOpenScene(const std::function<void (const std::string &fileName)> &value) = 0;
    virtual void setCallbackSaveScene(const std::function<void (const std::string &fileName)> &value) = 0;
    virtual void setCallbackExit(const std::function<void ()> &value) = 0;
};

#endif // USERINTERFACEGATEWAY_H
