#include "storagepropertyintjson.h"

void StoragePropertyIntJson::setValue(int value)
{
    jsonObject.insert("int", value);
}

void StoragePropertyIntJson::setName(const std::string &name)
{
    Q_UNUSED(name);
}
