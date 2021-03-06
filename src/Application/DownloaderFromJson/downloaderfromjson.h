#ifndef DOWNLOADERSTORAGEJSON_H
#define DOWNLOADERSTORAGEJSON_H

#include "../../export/Core/Gateway/downloadgateway.h"

class SettingJson;
class QJsonArray;
class QJsonObject;
class GameObject;

class DownloaderFromJson : public DownloadGateway
{
public:
    using uint = unsigned int;
    DownloaderFromJson(SettingJson *settingJson);
    std::unique_ptr<Scene> loadScene(const std::string &fileName) override;

private:
    inline uint toUint(int value) { return static_cast<uint>(value); }
    void loadProperty(QJsonArray jsonPropertyArray, GameObject *gameObject);
    bool loadGameObject(QJsonObject jsonMap, Scene *scene);
    SettingJson *settingJson;
};

#endif // DOWNLOADERSTORAGEJSON_H
