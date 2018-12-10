#include "propertyintcontrol.h"

void PropertyIntControl::setCallbackValueChange(const std::function<void (int)> &value)
{
    callbackValueChange = value;
}
