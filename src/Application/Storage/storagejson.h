#ifndef STORAGEJSON_H
#define STORAGEJSON_H

#include "../../export/Core/Gateway/storagegateway.h"

class StorageJson : public StorageGateway
{
public:
    StorageJson() = default;
    void saveScene(Scene *scene, const std::string &fileName) override;
    std::unique_ptr<Scene> loadScene(const std::string &fileName) override;
};

#endif // STORAGEJSON_H
