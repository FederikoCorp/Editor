#include "../../export/Core/Property/propertyliststate.h"

PropertyListState::PropertyListState(const std::string &name) : Property (name)
{

}

void PropertyListState::createPropertyControl(UserInterfaceGateway *userInterfaceGateWay)
{
    PropertyListStateControl *control = userInterfaceGateWay->createPropertyListStateControl();
    control->setName(name);
    for(std::string &s : vecState)
        control->addState(s);
    control->setValue(currentState);
    control->setCallbackValueChange([this](uint value){
        setCurrentState(value);
    });
}

std::unique_ptr<Property> PropertyListState::clone()
{
    PropertyListState *copy = new PropertyListState(name);
    copy->setCurrentState(currentState);
    for(std::string &state : vecState)
        copy->addState(state);
    std::unique_ptr<Property> ptr(copy);
    return ptr;
}

void PropertyListState::addState(const std::string &state)
{
    vecState.push_back(state);
}

std::string PropertyListState::getState(uint index) const
{
    return vecState.at(index);
}

uint PropertyListState::getCountState() const
{
    return vecState.size();
}

uint PropertyListState::getCurrentState() const
{
    return currentState;
}

void PropertyListState::setCurrentState(uint value)
{
    currentState = value;
}
