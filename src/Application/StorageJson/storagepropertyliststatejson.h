#ifndef STORAGEPROPERTYLISTSTATEJSON_H
#define STORAGEPROPERTYLISTSTATEJSON_H

#include "../../export/Core/StorageProperty/storagepropertyliststate.h"
#include "StorageJson/storagejson.h"

class StoragePropertyListStateJson : public StoragePropertyListState, public StorageJson
{
public:
    void setValue(unsigned int value) override;
    void setName(const std::string &name) override;
};

#endif // STORAGEPROPERTYLISTSTATEJSON_H
