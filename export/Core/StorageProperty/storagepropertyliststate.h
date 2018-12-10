#ifndef STORAGEPROPERTYLISTSTATE_H
#define STORAGEPROPERTYLISTSTATE_H

#include "storageproperty.h"

class StoragePropertyListState : public StorageProperty
{
public:
    StoragePropertyListState() = default;
    virtual ~StoragePropertyListState() = default;
    virtual void setValue(unsigned int value) = 0;
};

#endif // STORAGEPROPERTYLISTSTATE_H
