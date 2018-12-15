#include "../../export/Core/Property/propertyliststate.h"
#include "../../export/Core/Gateway/userinterfacegateway.h"
#include "../../export/Core/Gateway/unloadgateway.h"
#include "../../export/Core/PropertyControl/propertyliststatecontrol.h"
#include "../../export/Core/StorageProperty/storagepropertyliststate.h"

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

Property::StoragePropertyPtr PropertyListState::createStorageProperty(UnloadGateway *unloadGateway)
{
    std::unique_ptr<StoragePropertyListState> storage = unloadGateway->getStoragePropertyListState();
    storage->setValue(currentState);
    storage->setName(name);
    return std::move(storage);
}

Property::PropertyPtr PropertyListState::clone()
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
