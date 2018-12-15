#ifndef UNLOADGATEWAY_H
#define UNLOADGATEWAY_H

#include <memory>

class StoragePropertyInt;
class StoragePropertyFloat;
class StoragePropertyBool;
class StoragePropertyListState;
class StorageScene;
class StorageGameObject;

class UnloadGateway
{
public:
    UnloadGateway() = default;
    virtual ~UnloadGateway() = default;

    virtual std::unique_ptr<StoragePropertyInt> getStoragePropertyInt() = 0;
    virtual std::unique_ptr<StoragePropertyFloat> getStoragePropertyFloat() = 0;
    virtual std::unique_ptr<StoragePropertyBool> getStoragePropertyBool() = 0;
    virtual std::unique_ptr<StoragePropertyListState> getStoragePropertyListState() = 0;
    virtual std::unique_ptr<StorageScene> getStorageScene() = 0;
    virtual std::unique_ptr<StorageGameObject> getStorageGameObject() = 0;
    virtual void unload(const std::string &fileName, std::unique_ptr<StorageScene> scene) = 0;

};

#endif // UNLOADGATEWAY_H
