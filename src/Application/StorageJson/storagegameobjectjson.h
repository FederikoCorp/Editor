#ifndef STORAGEGAMEOBJECTJSON_H
#define STORAGEGAMEOBJECTJSON_H

#include <QJsonObject>
#include <QJsonArray>
#include "../../export/Core/StorageProperty/storagegameobject.h"
#include "StorageJson/storagejson.h"

class StorageGameObjectJson : public StorageGameObject, public StorageJson
{
public:
    StorageGameObjectJson();
    void addStorageProperty(std::unique_ptr<StorageProperty> storageProperty) override;
    void setPosition(uint x, uint y) override;
    void setName(const std::string &name) override;

};

#endif // STORAGEGAMEOBJECTJSON_H
