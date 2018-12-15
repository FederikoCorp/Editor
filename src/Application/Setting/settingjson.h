#ifndef SETTINGJSON_H
#define SETTINGJSON_H

#include "../../export/Core/Gateway/settinggateway.h"
#include <vector>
#include <unordered_map>

class GameObject;
class SceneObject;

using uint = unsigned int;

class SettingJson : public SettingGateway
{
public:
    SettingJson(const std::string &fileName);
    ~SettingJson() override;
    std::vector<std::unique_ptr<GameObject>>&  getAvailableGameObjects() override;
    GameObject *getGameObjectByName(const std::string &name);

private:
    std::vector<std::unique_ptr<GameObject>> availableGameObject;
    std::unordered_map<std::string, GameObject*> nameToGameObject;
};

#endif // SETTINGJSON_H
