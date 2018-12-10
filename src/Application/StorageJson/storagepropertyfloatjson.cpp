#include "storagepropertyfloatjson.h"

void StoragePropertyFloatJson::setValue(float value)
{
    jsonObject.insert("float", static_cast<double>(value));
}

void StoragePropertyFloatJson::setName(const std::string &name)
{
    Q_UNUSED(name);
}
