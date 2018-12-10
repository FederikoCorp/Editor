#ifndef STORAGEPROPERTYFLOAT_H
#define STORAGEPROPERTYFLOAT_H

#include "storageproperty.h"

class StoragePropertyFloat : public StorageProperty
{
public:
    StoragePropertyFloat() = default;
    virtual ~StoragePropertyFloat() = default;
    virtual void setValue(float value) = 0;
};

#endif // STORAGEPROPERTYFLOAT_H
