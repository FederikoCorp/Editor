#ifndef STORAGESCENEJSON_H
#define STORAGESCENEJSON_H

#include "../../export/Core/StorageProperty/storagescene.h"
#include "StorageJson/storagejson.h"

class StorageSceneJson : public StorageScene, public StorageJson
{
public:
    StorageSceneJson();
    void addStorageGameObject(std::unique_ptr<StorageGameObject> storageGameObject) override;
    void setSize(uint width, uint height) override;
};

#endif // STORAGESCENEJSON_H
