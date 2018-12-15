#ifndef STORAGESCENE_H
#define STORAGESCENE_H

#include <memory>

class StorageGameObject;

class StorageScene
{
public:
    using uint = unsigned int;

    StorageScene() = default;
    virtual ~StorageScene() = default;

    virtual void addStorageGameObject(std::unique_ptr<StorageGameObject> storageGameObject) = 0;
    virtual void setSize(uint width, uint height) = 0;
};

#endif // STORAGESCENE_H
