#include "../../export/Core/Property/propertyint.h"

PropertyInt::PropertyInt(const std::string &name) : Property (name)
{

}

void PropertyInt::createPropertyControl(UserInterfaceGateway *userInterfaceGateWay)
{
    PropertyIntControl *control = userInterfaceGateWay->createPropertyIntControl();
    control->setName(name);
    control->setMin(min);
    control->setMax(max);
    control->setValue(value);
    control->setCallbackValueChange([this](int value){ setValue(value); });
}

std::unique_ptr<StorageProperty> PropertyInt::getStorageProperty(UnloadGateway *unloadGateway)
{
    std::unique_ptr<StoragePropertyInt> storage = unloadGateway->getStoragePropertyInt();
    storage->setValue(value);
    storage->setName(name);
    return std::move(storage);
}

std::unique_ptr<Property> PropertyInt::clone()
{
    PropertyInt *copy = new PropertyInt(name);
    copy->setValue(value);
    copy->setMin(min);
    copy->setMax(max);
    std::unique_ptr<Property> ptr(copy);
    return ptr;
}

int PropertyInt::getValue() const
{
    return value;
}

void PropertyInt::setValue(int value)
{
    this->value = value;
}

int PropertyInt::getMin() const
{
    return min;
}

int PropertyInt::getMax() const
{
    return max;
}

void PropertyInt::setMin(int value)
{
    min = value;
}

void PropertyInt::setMax(int value)
{
    max = value;
}
