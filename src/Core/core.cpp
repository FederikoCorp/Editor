#include "../../export/Core/core.h"

Core::Core(UserInterfaceGateway *uiGateWay, SettingGateway *settingGateway, StorageGateway *storageGateway) :
    uiGateway(uiGateWay), settingGateway(settingGateway), storageGateway(storageGateway)
{
    loadAvailableGameObject();

    uiGateWay->setCallbackAddGameObject([this](uint x, uint y, uint index) { addGameObjectCallback(x, y, index); });
    uiGateWay->setCallbackSelectGameObject([this](uint x, uint y) { selectGameObjectCallback(x, y); });
    uiGateWay->setCallbackRemoveGameObject([this](uint x, uint y) { removeGameObjectCallback(x, y); });
    uiGateWay->setCallbackCreateScene([this](uint width, uint height) { createSceneCallback(width, height); });
    uiGateWay->setCallbackOpenScene([this](const std::string &fileName) { openSceneCallback(fileName); });
    uiGateWay->setCallbackSaveScene([this](const std::string &fileName) { saveSceneCallback(fileName); });
    uiGateWay->setCallbackExit([this]() {
        exitCallback();
    });
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

    SceneObject *sceneObject = vecAvailableGameObject.at(index)->getSceneObject().get();
    if(limitGameObject.find(sceneObject) != limitGameObject.end())
    {
        if(limitGameObject[sceneObject] == 0)
            return;
        limitGameObject[sceneObject] -= 1;
    }

    std::unique_ptr<GameObject> copy = vecAvailableGameObject.at(index)->clone();
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

    SceneObject *sceneObject = scene->getGameObject(x, y)->getSceneObject().get();
    if(limitGameObject.find(sceneObject) != limitGameObject.end())
        limitGameObject[sceneObject] += 1;

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
    limitGameObject = settingGateway->getLimitGameObject();

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
    scene = storageGateway->loadScene(fileName);

    for(unsigned int x = 0; x < scene->getWidth(); ++x)
        for(unsigned int y = 0; y < scene->getHeight(); ++y)
            uiGateway->addSceneObject(scene->getGameObject(x, y)->getSceneObject(), x, y);
}

void Core::saveSceneCallback(const std::string &fileName)
{
    if(!scene)
        return;
    if(fileName.empty())
        return;
    storageGateway->saveScene(scene.get(), fileName);
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
    vecAvailableGameObject = settingGateway->getAvailableGameObject();
    for(std::unique_ptr<GameObject> &obj : vecAvailableGameObject)
        uiGateway->addGameObjectTool(obj->getSceneObject(), obj->getName());
}
