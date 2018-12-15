#ifndef PROPERTY_H
#define PROPERTY_H

#include <memory>
#include <string>

class UserInterfaceGateway;
class UnloadGateway;
class StorageProperty;

class Property
{
public:
    using StoragePropertyPtr = std::unique_ptr<StorageProperty>;
    using PropertyPtr = std::unique_ptr<Property>;

    Property(const std::string &name);
    virtual ~Property() = default;

    virtual void createPropertyControl(UserInterfaceGateway *userInterfaceGateWay) = 0;
    virtual StoragePropertyPtr createStorageProperty(UnloadGateway *unloadGateway) = 0;
    virtual PropertyPtr clone() = 0;

protected:
    std::string name;
};

#endif // PROPERTY_H
