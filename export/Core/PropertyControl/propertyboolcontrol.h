#ifndef PROPERTYBOOLCONTROL_H
#define PROPERTYBOOLCONTROL_H

#include "propertycontrol.h"

class PropertyBoolControl : public PropertyControl
{
public:
    PropertyBoolControl() = default;
    ~PropertyBoolControl() override = default;
    virtual void setValue(bool value) = 0;
    void setCallbackValueChange(const std::function<void (bool)> &value);

protected:
    std::function<void(bool)> callbackValueChange;
};

#endif // PROPERTYBOOLCONTROL_H
