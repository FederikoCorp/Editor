#ifndef STORAGEPROPERTYBOOL_H
#define STORAGEPROPERTYBOOL_H

#include "storageproperty.h"

class StoragePropertyBool : public StorageProperty
{
public:
    StoragePropertyBool() = default;
    virtual ~StoragePropertyBool() = default;
    virtual void setValue(bool value) = 0;
};

#endif // STORAGEPROPERTYBOOL_H
