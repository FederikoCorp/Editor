#include "../../export/Core/Property/propertyfloat.h"
#include "../../export/Core/Gateway/userinterfacegateway.h"
#include "../../export/Core/Gateway/unloadgateway.h"
#include "../../export/Core/PropertyControl/propertyfloatcontrol.h"
#include "../../export/Core/StorageProperty/storagepropertyfloat.h"

PropertyFloat::PropertyFloat(const std::string &name) : Property (name)
{

}

void PropertyFloat::createPropertyControl(UserInterfaceGateway *userInterfaceGateWay)
{
    PropertyFloatControl *control = userInterfaceGateWay->createPropertyFloatControl(); 
    control->setName(name);
    control->setMin(min);
    control->setMax(max);
    control->setValue(value);
    control->setCallbackValueChange([this](float value){ setValue(value); });
}

Property::StoragePropertyPtr PropertyFloat::createStorageProperty(UnloadGateway *unloadGateway)
{
    std::unique_ptr<StoragePropertyFloat> storage = unloadGateway->getStoragePropertyFloat();
    storage->setValue(value);
    storage->setName(name);
    return std::move(storage);
}

Property::PropertyPtr PropertyFloat::clone()
{
    PropertyFloat *copy = new PropertyFloat(name);
    copy->setValue(value);
    copy->setMin(min);
    copy->setMax(max);
    std::unique_ptr<Property> ptr(copy);
    return ptr;
}

float PropertyFloat::getValue() const
{
    return value;
}

void PropertyFloat::setValue(float value)
{
    this->value = value;
}

float PropertyFloat::getMin() const
{
    return min;
}

void PropertyFloat::setMin(float value)
{
    min = value;
}

float PropertyFloat::getMax() const
{
    return max;
}

void PropertyFloat::setMax(float value)
{
    max = value;
}
