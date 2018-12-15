#include "../../export/Core/core.h"
#include "../../export/Core/gameobject.h"
#include "../../export/Core/scene.h"
#include "../../export/Core/Property/property.h"

#include "../../export/Core/Gateway/userinterfacegateway.h"
#include "../../export/Core/Gateway/settinggateway.h"
#include "../../export/Core/Gateway/downloadgateway.h"
#include "../../export/Core/Gateway/unloadgateway.h"

#include "../../export/Core/StorageProperty/storagescene.h"
#include "../../export/Core/StorageProperty/storagegameobject.h"
#include "../../export/Core/StorageProperty/storageproperty.h"

struct Core::CoreData
{
    UserInterfaceGateway *uiGateway;
    SettingGateway *settingGateway;
    DownloadGateway *downloadGateway;
    UnloadGateway *unloadGateway;
    std::unique_ptr<Scene> scene;
};

Core::Core(UserInterfaceGateway *uiGateWay, SettingGateway *settingGateway, DownloadGateway *downloadGateway, UnloadGateway *unloadGateway) :
    data(new CoreData)
{
    data->uiGateway = uiGateWay;
    data->settingGateway =  settingGateway;
    data->downloadGateway = downloadGateway;
    data->unloadGateway = unloadGateway;

    loadAvailableGameObject();

    uiGateWay->setCallbackAddGameObject([this](uint x, uint y, uint index) { addGameObjectCallback(x, y, index); });
    uiGateWay->setCallbackSelectGameObject([this](uint x, uint y) { selectGameObjectCallback(x, y); });
    uiGateWay->setCallbackRemoveGameObject([this](uint x, uint y) { removeGameObjectCallback(x, y); });
    uiGateWay->setCallbackCreateScene([this](uint width, uint height) { createSceneCallback(width, height); });
    uiGateWay->setCallbackOpenScene([this](const std::string &fileName) { openSceneCallback(fileName); });
    uiGateWay->setCallbackSaveScene([this](const std::string &fileName) { saveSceneCallback(fileName); });
    uiGateWay->setCallbackExit([this]() { exitCallback(); });
}

Core::~Core() = default;

void Core::addGameObjectCallback(uint x, uint y, uint index)
{
    if(!data->scene)
        return;
    if (x >= data->scene->getWidth() || y >= data->scene->getHeight())
        return;
    if(data->scene->isGameObject(x, y))
    {
        selectGameObjectCallback(x, y);
        return;
    }

    GameObject *gameObject = data->settingGateway->getAvailableGameObjects().at(index).get();
    std::unique_ptr<GameObject> copy = gameObject->clone(); 
    if(!copy)
        return;
    copy->setPosition(x, y);

    data->uiGateway->destroyPropertyControls();
    createPropertyControl(copy.get());

    data->uiGateway->addSceneObject(copy->getSceneObject(), x, y);
    data->uiGateway->selectSceneObject(x, y);

    data->scene->addGameObject(std::move(copy));
}

void Core::selectGameObjectCallback(uint x, uint y)
{
    if(!data->scene)
        return;
    data->uiGateway->selectSceneObject(x, y);
    data->uiGateway->destroyPropertyControls();
    if (x >= data->scene->getWidth() || y >= data->scene->getHeight())
        return;
    if(!data->scene->isGameObject(x, y))
        return;
    GameObject *gameObject = data->scene->getGameObject(x, y);
    createPropertyControl(gameObject);
}

void Core::removeGameObjectCallback(uint x, uint y)
{
    if(!data->scene)
        return;
    if (x >= data->scene->getWidth() || y >= data->scene->getHeight())
        return;
    if(!data->scene->isGameObject(x, y))
        return;

    data->uiGateway->destroyPropertyControls();
    data->scene->removeGameObject(x, y);
    data->uiGateway->selectSceneObject(x, y);
    data->uiGateway->removeSceneObject(x, y);
}

void Core::createSceneCallback(uint width, uint height)
{
    if(width == 0 || height == 0)
        return;
    data->scene = std::make_unique<Scene>(width, height);

    data->uiGateway->destroyPropertyControls();
    data->uiGateway->clearScene();
    data->uiGateway->createScene(width, height);
}

void Core::openSceneCallback(const std::string &fileName)
{
    if(fileName.empty())
        return;
    data->uiGateway->destroyPropertyControls();
    data->uiGateway->clearScene();
    data->scene = data->downloadGateway->loadScene(fileName);
    if(!data->scene)
        return;

    data->uiGateway->createScene(data->scene->getWidth(), data->scene->getHeight());
    for(unsigned int x = 0; x < data->scene->getWidth(); ++x)
    {
        for(unsigned int y = 0; y < data->scene->getHeight(); ++y)
        {
            if(data->scene->isGameObject(x, y))
                data->uiGateway->addSceneObject(data->scene->getGameObject(x, y)->getSceneObject(), x, y);
        }
    }
}

void Core::saveSceneCallback(const std::string &fileName)
{
    if(!data->scene)
        return;
    if(fileName.empty())
        return;

    std::unique_ptr<StorageScene> storageScene = data->unloadGateway->getStorageScene();
    storageScene->setSize(data->scene->getWidth(), data->scene->getHeight());

    for(auto it = data->scene->begin(); it != data->scene->end(); ++it)
    {
        GameObject *gameObject = it->second.get();

        std::unique_ptr<StorageGameObject> storageGameObject = data->unloadGateway->getStorageGameObject();
        storageGameObject->setName(gameObject->getName());
        storageGameObject->setPosition(gameObject->getX(), gameObject->getY());

        for(uint i = 0; i < gameObject->getCountProperty(); ++i)
        {
            std::unique_ptr<StorageProperty> storageProperty = gameObject->getProperty(i)->createStorageProperty(data->unloadGateway);
            storageGameObject->addStorageProperty(std::move(storageProperty));
        }
        storageScene->addStorageGameObject(std::move(storageGameObject));
    }
    data->unloadGateway->unload(fileName, std::move(storageScene));
}

void Core::exitCallback()
{
    data->uiGateway->exit();
}

void Core::createPropertyControl(GameObject *gameObject)
{
    for(unsigned int i = 0; i < gameObject->getCountProperty(); ++i)
        gameObject->getProperty(i)->createPropertyControl(data->uiGateway);
}

void Core::loadAvailableGameObject()
{
    for(std::unique_ptr<GameObject> &obj : data->settingGateway->getAvailableGameObjects())
        data->uiGateway->addGameObjectTool(obj->getSceneObject(), obj->getName());
}
