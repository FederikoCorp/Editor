#ifndef STORAGEPROPERTYINTJSON_H
#define STORAGEPROPERTYINTJSON_H

#include "../../export/Core/StorageProperty/storagepropertyint.h"
#include "StorageJson/storagejson.h"

class StoragePropertyIntJson : public StoragePropertyInt, public StorageJson
{
public:
    void setValue(int value) override;
    void setName(const std::string &name) override;
};

#endif // STORAGEPROPERTYINTJSON_H
