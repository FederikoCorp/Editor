#include "storagegameobjectjson.h"

StorageGameObjectJson::StorageGameObjectJson()
{
    jsonObject.insert("property", {});
}

void StorageGameObjectJson::addStorageProperty(std::unique_ptr<StorageProperty> storageProperty)
{
    StorageJson *jsonProperty = dynamic_cast<StorageJson*>(storageProperty.get());
    QJsonArray array = jsonObject["property"].toArray();
    array.push_back(jsonProperty->getJsonObject());
    jsonObject.insert("property", array);
}

void StorageGameObjectJson::setPosition(uint x, uint y)
{
    jsonObject.insert("x", static_cast<int>(x));
    jsonObject.insert("y", static_cast<int>(y));
}

void StorageGameObjectJson::setName(const std::string &name)
{
    jsonObject.insert("object", name.c_str());
}
