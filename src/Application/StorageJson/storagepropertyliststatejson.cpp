#include "storagepropertyliststatejson.h"

void StoragePropertyListStateJson::setValue(unsigned int value)
{
    jsonObject.insert("list", static_cast<int>(value));
}

void StoragePropertyListStateJson::setName(const std::string &name)
{
    Q_UNUSED(name);
}
