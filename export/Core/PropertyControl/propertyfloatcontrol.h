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
    virtual void setCallbackValueChange(const std::function<void (float)> &callback) = 0;
};

#endif // PROPERTYFLOATCONTROL_H
