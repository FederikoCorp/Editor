#include "storagepropertybooljson.h"

void StoragePropertyBoolJson::setValue(bool value)
{
    jsonObject.insert("bool", value);
}

void StoragePropertyBoolJson::setName(const std::string &name)
{
    Q_UNUSED(name);
}
