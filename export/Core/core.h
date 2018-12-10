#ifndef CORE_H
#define CORE_H

#include "Gateway/userinterfacegateway.h"
#include "Gateway/settinggateway.h"
#include "Gateway/downloadgateway.h"
#include "../Core/gameobject.h"
#include "../Core/scene.h"

//Класс отвечает за управление программой.
//Так как функций мало, не стал дробить на несколько классов
class Core
{
public:
    Core(UserInterfaceGateway *uiGateWay, SettingGateway *settingGateway, DownloadGateway *downloadGateway, UnloadGateway *unloadGateway);

private:
    void addGameObjectCallback(uint x, uint y, uint index);
    void selectGameObjectCallback(uint x, uint y);
    void removeGameObjectCallback(uint x, uint y);
    void createSceneCallback(uint width, uint height);
    void openSceneCallback(const std::string &fileName);
    void saveSceneCallback(const std::string &fileName);
    void exitCallback();

    void createPropertyControl(GameObject *gameObject);
    void loadAvailableGameObject();

    UserInterfaceGateway *uiGateway;
    SettingGateway *settingGateway;
    DownloadGateway *downloadGateway;
    UnloadGateway *unloadGateway;

    std::unique_ptr<Scene> scene;
};

#endif // CORE_H
