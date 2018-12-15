#ifndef STORAGEGAMEOBJECT_H
#define STORAGEGAMEOBJECT_H

#include <string>
#include <memory>

class StorageProperty;

class StorageGameObject
{
public:
    using uint = unsigned int;

    StorageGameObject() = default;
    virtual ~StorageGameObject() = default;

    virtual void addStorageProperty(std::unique_ptr<StorageProperty> storageProperty) = 0;
    virtual void setPosition(uint x, uint y) = 0;
    virtual void setName(const std::string &name) = 0;
};

#endif // STORAGEGAMEOBJECT_H
