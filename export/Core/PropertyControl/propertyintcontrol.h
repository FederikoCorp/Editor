#ifndef PROPERTYINTCONTROL_H
#define PROPERTYINTCONTROL_H

#include "propertycontrol.h"

class PropertyIntControl : public PropertyControl
{
public:
    PropertyIntControl() = default;
    ~PropertyIntControl() override = default;

    virtual void setValue(int value) = 0;
    virtual void setMin(int value) = 0;
    virtual void setMax(int value) = 0;
    virtual void setCallbackValueChange(const std::function<void (int)> &callback) = 0;
};

#endif // PROPERTYINTCONTROL_H
