#ifndef STORAGEGATEWAY_H
#define STORAGEGATEWAY_H

#include "../Core/scene.h"

class StorageGateway
{
public:
    StorageGateway() = default;
    virtual ~StorageGateway() = default;
    virtual void saveScene(Scene *scene, const std::string &fileName) = 0;
    virtual std::unique_ptr<Scene> loadScene(const std::string &fileName) = 0;
};

#endif // STORAGEGATEWAY_H
