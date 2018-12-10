#ifndef SETTINGJSON_H
#define SETTINGJSON_H

#include "../../export/Core/Gateway/settinggateway.h"
#include "SceneObject/sceneobjectasimage.h"
#include "../../export/Core/Property/propertybool.h"
#include "../../export/Core/Property/propertyfloat.h"
#include "../../export/Core/Property/propertyint.h"
#include "../../export/Core/Property/propertyliststate.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QFile>

using uint = unsigned int;

class SettingJson : public SettingGateway
{
public:
    SettingJson(const std::string &fileName);
    std::vector<std::unique_ptr<GameObject>>&  getAvailableGameObjects() override;
    std::unordered_map<SceneObject*, uint> getLimitGameObject() override;
    GameObject *getGameObjectByName(const std::string &name);

private:
    std::vector<std::unique_ptr<GameObject>> availableGameObject;
    std::unordered_map<SceneObject*, uint> limitGameObject;
    std::unordered_map<std::string, GameObject*> nameToGameObject;
};

#endif // SETTINGJSON_H
