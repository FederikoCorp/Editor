#ifndef STORAGEPROPERTY_H
#define STORAGEPROPERTY_H

#include <string>

class StorageProperty
{
public:
    StorageProperty() = default;
    virtual ~StorageProperty() = default;
    virtual void setName(const std::string &name) = 0;
};

#endif // STORAGEPROPERTY_H
