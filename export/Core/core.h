#ifndef CORE_H
#define CORE_H

#include <memory>

class GameObject;
class Scene;
class UserInterfaceGateway;
class SettingGateway;
class DownloadGateway;
class UnloadGateway;

class Core
{
public:
    using uint = unsigned int; 
    Core(UserInterfaceGateway *uiGateWay, SettingGateway *settingGateway, DownloadGateway *downloadGateway, UnloadGateway *unloadGateway);
    ~Core();

private:
    struct CoreData;
    std::unique_ptr<CoreData> data;

    void addGameObjectCallback(uint x, uint y, uint index);
    void selectGameObjectCallback(uint x, uint y);
    void removeGameObjectCallback(uint x, uint y);
    void createSceneCallback(uint width, uint height);
    void openSceneCallback(const std::string &fileName);
    void saveSceneCallback(const std::string &fileName);
    void exitCallback();

    void createPropertyControl(GameObject *gameObject);
    void loadAvailableGameObject();
};

#endif // CORE_H
