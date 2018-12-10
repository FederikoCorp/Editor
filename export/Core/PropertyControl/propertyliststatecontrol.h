#ifndef PROPERTYLISTSTATECONTROL_H
#define PROPERTYLISTSTATECONTROL_H

#include <vector>
#include <string>
#include "propertycontrol.h"

class PropertyListStateControl : public PropertyControl
{
public:
    PropertyListStateControl() = default;
    ~PropertyListStateControl() override = default;
    virtual void setValue(unsigned int value) = 0;
    void setCallbackValueChange(const std::function<void (unsigned int)> &value);
    virtual void addState(const std::string &state) = 0;

protected:
    std::function<void(unsigned int)> callbackValueChange;
};

#endif // PROPERTYLISTSTATECONTROL_H
