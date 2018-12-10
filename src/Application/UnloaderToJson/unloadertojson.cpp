#include "unloadertojson.h"

UnloaderToJson::UnloaderToJson()
{

}

std::unique_ptr<StoragePropertyInt> UnloaderToJson::getStoragePropertyInt()
{
    return std::make_unique<StoragePropertyIntJson>();
}

std::unique_ptr<StoragePropertyFloat> UnloaderToJson::getStoragePropertyFloat()
{
    return std::make_unique<StoragePropertyFloatJson>();
}

std::unique_ptr<StoragePropertyBool> UnloaderToJson::getStoragePropertyBool()
{
    return std::make_unique<StoragePropertyBoolJson>();
}

std::unique_ptr<StoragePropertyListState> UnloaderToJson::getStoragePropertyListState()
{
    return std::make_unique<StoragePropertyListStateJson>();
}

std::unique_ptr<StorageScene> UnloaderToJson::getStorageScene()
{
    return std::make_unique<StorageSceneJson>();
}

std::unique_ptr<StorageGameObject> UnloaderToJson::getStorageGameObject()
{
    return std::make_unique<StorageGameObjectJson>();
}

void UnloaderToJson::unload(const std::string &fileName, std::unique_ptr<StorageScene> scene)
{
    QFile fileMap(fileName.c_str());
    if(!fileMap.open(QIODevice::WriteOnly))
        return;

    QJsonDocument document;
    StorageSceneJson *jsonScene = dynamic_cast<StorageSceneJson*>(scene.get());
    document.setObject(jsonScene->getJsonObject());

    fileMap.write(document.toJson());

    fileMap.close();
}
