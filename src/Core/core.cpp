#include "../../export/Core/core.h"

Core::Core(UserInterfaceGateway *uiGateWay, SettingGateway *settingGateway, DownloadGateway *storageGateway, UnloadGateway *unloadGateway) :
    uiGateway(uiGateWay), settingGateway(settingGateway), downloadGateway(storageGateway), unloadGateway(unloadGateway)
{
    loadAvailableGameObject();

    uiGateWay->setCallbackAddGameObject([this](uint x, uint y, uint index) { addGameObjectCallback(x, y, index); });
    uiGateWay->setCallbackSelectGameObject([this](uint x, uint y) { selectGameObjectCallback(x, y); });
    uiGateWay->setCallbackRemoveGameObject([this](uint x, uint y) { removeGameObjectCallback(x, y); });
    uiGateWay->setCallbackCreateScene([this](uint width, uint height) { createSceneCallback(width, height); });
    uiGateWay->setCallbackOpenScene([this](const std::string &fileName) { openSceneCallback(fileName); });
    uiGateWay->setCallbackSaveScene([this](const std::string &fileName) { saveSceneCallback(fileName); });
    uiGateWay->setCallbackExit([this]() { exitCallback(); });
}

void Core::addGameObjectCallback(uint x, uint y, uint index)
{
    if(!scene)
        return;
    if (x >= scene->getWidth() || y >= scene->getHeight())
        return;
    if(scene->isGameObject(x, y))
    {
        selectGameObjectCallback(x, y);
        return;
    }

    GameObject *gameObject = settingGateway->getAvailableGameObjects().at(index).get();
    if(scene->isLimit(gameObject))
    {
        if(scene->getLimit(gameObject) == 0)
            return;
        scene->decLimit(gameObject);
    }

    std::unique_ptr<GameObject> copy = gameObject->clone();
    uiGateway->destroyPropertyControls();
    createPropertyControl(copy.get());

    uiGateway->addSceneObject(copy->getSceneObject(), x, y);
    uiGateway->selectSceneObject(x, y);

    scene->addGameObject(std::move(copy), x, y);
}

void Core::selectGameObjectCallback(uint x, uint y)
{
    if(!scene)
        return;
    uiGateway->selectSceneObject(x, y);
    uiGateway->destroyPropertyControls();
    if (x >= scene->getWidth() || y >= scene->getHeight())
        return;
    if(!scene->isGameObject(x, y))
        return;
    GameObject *gameObject = scene->getGameObject(x, y);
    createPropertyControl(gameObject);
}

void Core::removeGameObjectCallback(uint x, uint y)
{
    if(!scene)
        return;
    if (x >= scene->getWidth() || y >= scene->getHeight())
        return;
    if(!scene->isGameObject(x, y))
        return;

    if(scene->isLimit(scene->getGameObject(x, y)))
        scene->incLimit(scene->getGameObject(x, y));

    uiGateway->destroyPropertyControls();
    scene->removeGameObject(x, y);
    uiGateway->selectSceneObject(x, y);
    uiGateway->removeSceneObject(x, y);
}

void Core::createSceneCallback(uint width, uint height)
{
    if(width == 0 || height == 0)
        return;
    scene = std::make_unique<Scene>(width, height);
    scene->setLimitGameObject(settingGateway->getLimitGameObject());

    uiGateway->destroyPropertyControls();
    uiGateway->clearScene();
    uiGateway->createScene(width, height);
}

void Core::openSceneCallback(const std::string &fileName)
{
    if(fileName.empty())
        return;
    uiGateway->destroyPropertyControls();
    uiGateway->clearScene();
    scene = downloadGateway->loadScene(fileName);
    if(!scene)
        return;

    uiGateway->createScene(scene->getWidth(), scene->getHeight());
    for(unsigned int x = 0; x < scene->getWidth(); ++x)
    {
        for(unsigned int y = 0; y < scene->getHeight(); ++y)
        {
            if(scene->isGameObject(x, y))
                uiGateway->addSceneObject(scene->getGameObject(x, y)->getSceneObject(), x, y);
        }
    }
}

void Core::saveSceneCallback(const std::string &fileName)
{
    if(!scene)
        return;
    if(fileName.empty())
        return;
    std::unique_ptr<StorageScene> storageScene = unloadGateway->getStorageScene();
    storageScene->setSize(scene->getWidth(), scene->getHeight());
    auto sceneMap = scene->getGameObjectPositionMap();
    for(auto it = sceneMap.begin(); it != sceneMap.end(); ++it)
    {
        std::unique_ptr<StorageGameObject> storageGameObject = unloadGateway->getStorageGameObject();
        storageGameObject->setName(it->first->getName());
        auto pos = it->second;
        storageGameObject->setPosition(pos.first, pos.second);
        GameObject *gameObject = it->first;
        for(uint i = 0; i < gameObject->getCountProperty(); ++i)
        {
            std::unique_ptr<StorageProperty> storageProperty = gameObject->getProperty(i)->getStorageProperty(unloadGateway);
            storageGameObject->addStorageProperty(std::move(storageProperty));
        }
        storageScene->addStorageGameObject(std::move(storageGameObject));
    }
    unloadGateway->unload(fileName, std::move(storageScene));
}

void Core::exitCallback()
{
    //Можно конечно вызвать exit просто в ui, не знаю как лучше
    //По идее здесь должны спрашивать надо ли сохранять
    uiGateway->exit();
}

void Core::createPropertyControl(GameObject *gameObject)
{
    for(unsigned int i = 0; i < gameObject->getCountProperty(); ++i)
        gameObject->getProperty(i)->createPropertyControl(uiGateway);
}

void Core::loadAvailableGameObject()
{
    for(std::unique_ptr<GameObject> &obj : settingGateway->getAvailableGameObjects())
        uiGateway->addGameObjectTool(obj->getSceneObject(), obj->getName());
}
