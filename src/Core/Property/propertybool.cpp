#include "../../export/Core/Property/propertybool.h"
#include "../../export/Core/Gateway/userinterfacegateway.h"
#include "../../export/Core/Gateway/unloadgateway.h"
#include "../../export/Core/PropertyControl/propertyboolcontrol.h"
#include "../../export/Core/StorageProperty/storagepropertybool.h"

PropertyBool::PropertyBool(const std::string &name) : Property (name)
{

}

void PropertyBool::createPropertyControl(UserInterfaceGateway *userInterfaceGateWay)
{
    PropertyBoolControl *control = userInterfaceGateWay->createPropertyBoolControl();
    control->setValue(value);
    control->setName(name);
    control->setCallbackValueChange([this](bool value){ setValue(value); });
}

Property::StoragePropertyPtr PropertyBool::createStorageProperty(UnloadGateway *unloadGateway)
{
    std::unique_ptr<StoragePropertyBool> storage = unloadGateway->getStoragePropertyBool();
    storage->setValue(value);
    storage->setName(name);
    return std::move(storage);
}

Property::PropertyPtr PropertyBool::clone()
{
    PropertyBool *copy = new PropertyBool(name);
    copy->setValue(value);
    std::unique_ptr<Property> ptr(copy);
    return ptr;
}

bool PropertyBool::getValue() const
{
    return value;
}

void PropertyBool::setValue(bool value)
{
    this->value = value;
}
