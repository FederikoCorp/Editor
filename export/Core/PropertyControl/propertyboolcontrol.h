#ifndef PROPERTYBOOLCONTROL_H
#define PROPERTYBOOLCONTROL_H

#include "propertycontrol.h"

class PropertyBoolControl : public PropertyControl
{
public:
    PropertyBoolControl() = default;
    ~PropertyBoolControl() override = default;

    virtual void setValue(bool value) = 0;
    virtual void setCallbackValueChange(const std::function<void (bool)> &callback) = 0;
};

#endif // PROPERTYBOOLCONTROL_H
