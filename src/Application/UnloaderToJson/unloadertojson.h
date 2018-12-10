#ifndef UNLOADERTOJSON_H
#define UNLOADERTOJSON_H

#include <QFile>
#include <QJsonDocument>
#include "../../export/Core/Gateway/unloadgateway.h"
#include "StorageJson/storagegameobjectjson.h"
#include "StorageJson/storagepropertybooljson.h"
#include "StorageJson/storagepropertyfloatjson.h"
#include "StorageJson/storagepropertyintjson.h"
#include "StorageJson/storagepropertyliststatejson.h"
#include "StorageJson/storagescenejson.h"

class UnloaderToJson : public UnloadGateway
{
public:
    UnloaderToJson();
    std::unique_ptr<StoragePropertyInt> getStoragePropertyInt() override;
    std::unique_ptr<StoragePropertyFloat> getStoragePropertyFloat() override;
    std::unique_ptr<StoragePropertyBool> getStoragePropertyBool() override;
    std::unique_ptr<StoragePropertyListState> getStoragePropertyListState() override;
    std::unique_ptr<StorageScene> getStorageScene() override;
    std::unique_ptr<StorageGameObject> getStorageGameObject() override;
    void unload(const std::string &fileName, std::unique_ptr<StorageScene> scene) override;
};

#endif // UNLOADERTOJSON_H
