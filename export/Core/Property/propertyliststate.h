#ifndef PROPERTYLISTSTATE_H
#define PROPERTYLISTSTATE_H

#include <string>
#include <vector>
#include "property.h"

class PropertyListState : public Property
{
public:
    using uint = unsigned int;

    PropertyListState(const std::string& name);
    ~PropertyListState() override = default;

    void createPropertyControl(UserInterfaceGateway *userInterfaceGateWay) override;
    StoragePropertyPtr createStorageProperty(UnloadGateway *unloadGateway) override;
    PropertyPtr clone() override;

    void addState(const std::string &state);
    std::string getState(uint index) const;
    uint getCountState() const;
    uint getCurrentState() const;
    void setCurrentState(uint value);

private:
    std::vector<std::string> vecState;
    uint currentState = 0;
};

#endif // PROPERTYLISTSTATE_H
