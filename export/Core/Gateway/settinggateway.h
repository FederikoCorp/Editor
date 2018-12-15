#ifndef SETTINGGATEWAY_H
#define SETTINGGATEWAY_H

#include <unordered_map>
#include <vector>
#include <memory>

class SceneObject;
class GameObject;

class SettingGateway
{
public:
    using uint = unsigned int;
    SettingGateway() = default;
    virtual ~SettingGateway() = default;
    virtual std::vector<std::unique_ptr<GameObject>>&  getAvailableGameObjects() = 0;
};

#endif // SETTINGGATEWAY_H
