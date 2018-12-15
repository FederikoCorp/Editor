#ifndef UNLOADERTOJSON_H
#define UNLOADERTOJSON_H

#include "../../export/Core/Gateway/unloadgateway.h"

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
