#ifndef STORAGEPROPERTYINT_H
#define STORAGEPROPERTYINT_H

#include "storageproperty.h"

class StoragePropertyInt : public StorageProperty
{
public:
    StoragePropertyInt() = default;
    virtual ~StoragePropertyInt() = default;
    virtual void setValue(int value) = 0;
};

#endif // STORAGEPROPERTYINT_H
