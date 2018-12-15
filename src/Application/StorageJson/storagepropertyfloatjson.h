#ifndef STORAGEPROPERTYFLOATJSON_H
#define STORAGEPROPERTYFLOATJSON_H

#include "../../export/Core/StorageProperty/storagepropertyfloat.h"
#include "StorageJson/storagejson.h"

class StoragePropertyFloatJson : public StoragePropertyFloat, public StorageJson
{
public:
    void setValue(float value) override;
    void setName(const std::string &name) override;
};

#endif // STORAGEPROPERTYFLOATJSON_H
