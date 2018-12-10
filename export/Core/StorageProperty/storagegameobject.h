#ifndef STORAGEGAMEOBJECT_H
#define STORAGEGAMEOBJECT_H

#include "storageproperty.h"
#include <string>
#include <memory>

using uint = unsigned int;

class StorageGameObject
{
public:
    StorageGameObject() = default;
    virtual ~StorageGameObject() = default;
    virtual void addStorageProperty(std::unique_ptr<StorageProperty> storageProperty) = 0;
    virtual void setPosition(uint x, uint y) = 0;
    virtual void setName(const std::string &name) = 0;
};

#endif // STORAGEGAMEOBJECT_H
