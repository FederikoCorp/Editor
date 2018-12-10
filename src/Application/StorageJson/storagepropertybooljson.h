#ifndef STORAGEPROPERTYBOOLJSON_H
#define STORAGEPROPERTYBOOLJSON_H

#include <QJsonObject>
#include "../../export/Core/StorageProperty/storagepropertybool.h"
#include "StorageJson/storagejson.h"

class StoragePropertyBoolJson : public StoragePropertyBool, public StorageJson
{
public:
    void setValue(bool value) override;
    void setName(const std::string &name) override;
};

#endif // STORAGEPROPERTYBOOLJSON_H
