#ifndef PROPERTYFLOATCONTROL_H
#define PROPERTYFLOATCONTROL_H

#include "propertycontrol.h"

class PropertyFloatControl : public PropertyControl
{
public:
    PropertyFloatControl() = default;
    ~PropertyFloatControl() override = default;
    virtual void setValue(float value) = 0;
    virtual void setMin(float value) = 0;
    virtual void setMax(float value) = 0;
    void setCallbackValueChange(const std::function<void (float)> &value);

protected:
    std::function<void(float)> callbackValueChange;
};

#endif // PROPERTYFLOATCONTROL_H
