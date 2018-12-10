#ifndef SETTINGGATEWAY_H
#define SETTINGGATEWAY_H

#include "../Core/gameobject.h"

class SettingGateway
{
public:
    SettingGateway() = default;
    virtual ~SettingGateway() = default;
    virtual std::vector<std::unique_ptr<GameObject>>&  getAvailableGameObjects() = 0;
    virtual std::unordered_map<SceneObject*, uint> getLimitGameObject() = 0;
};

#endif // SETTINGGATEWAY_H
