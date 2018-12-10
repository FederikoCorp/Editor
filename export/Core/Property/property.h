#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
#include "../../export/Core/Gateway/userinterfacegateway.h"
#include "../../export/Core/Gateway/unloadgateway.h"

class Property
{
public:
    Property(const std::string &name);
    virtual ~Property() = default;

    virtual void createPropertyControl(UserInterfaceGateway *userInterfaceGateWay) = 0;
    virtual std::unique_ptr<StorageProperty> getStorageProperty(UnloadGateway *unloadGateway) = 0;
    virtual std::unique_ptr<Property> clone() = 0;

protected:
    std::string name;
};

#endif // PROPERTY_H
