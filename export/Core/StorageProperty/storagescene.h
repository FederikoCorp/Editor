#ifndef STORAGESCENE_H
#define STORAGESCENE_H

#include "storagegameobject.h"

class StorageScene
{
public:
    StorageScene() = default;
    virtual ~StorageScene() = default;
    virtual void addStorageGameObject(std::unique_ptr<StorageGameObject> storageGameObject) = 0;
    virtual void setSize(uint width, uint height) = 0;
};

#endif // STORAGESCENE_H
