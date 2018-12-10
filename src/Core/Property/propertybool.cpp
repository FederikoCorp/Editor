#include "../../export/Core/Property/propertybool.h"

PropertyBool::PropertyBool(const std::string &name) : Property (name)
{

}

void PropertyBool::createPropertyControl(UserInterfaceGateway *userInterfaceGateWay)
{
    PropertyBoolControl *control = userInterfaceGateWay->createPropertyBoolControl();
    control->setValue(value); //перенести в конструктор
    control->setName(name);
    control->setCallbackValueChange([this](bool value){ setValue(value); });
}

std::unique_ptr<Property> PropertyBool::clone()
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
