#include "storagescenejson.h"

StorageSceneJson::StorageSceneJson()
{
    jsonObject.insert("width", 0);
    jsonObject.insert("height", 0);
    jsonObject.insert("objects", {});
}

void StorageSceneJson::addStorageGameObject(std::unique_ptr<StorageGameObject> storageGameObject)
{
    StorageJson *jsonProperty = dynamic_cast<StorageJson*>(storageGameObject.get());
    QJsonArray array = jsonObject["objects"].toArray();
    array.push_back(jsonProperty->getJsonObject());
    jsonObject.insert("objects", array);
}

void StorageSceneJson::setSize(uint width, uint height)
{
    jsonObject.insert("width", static_cast<int>(width));
    jsonObject.insert("height", static_cast<int>(height));
}
