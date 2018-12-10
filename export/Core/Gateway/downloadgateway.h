#ifndef STORAGEGATEWAY_H
#define STORAGEGATEWAY_H

#include "../Core/scene.h"

class DownloadGateway
{
public:
    DownloadGateway() = default;
    virtual ~DownloadGateway() = default;
    virtual std::unique_ptr<Scene> loadScene(const std::string &fileName) = 0;
};

#endif // STORAGEGATEWAY_H
