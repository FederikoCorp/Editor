#include "propertyboolcontrol.h"

void PropertyBoolControl::setCallbackValueChange(const std::function<void (bool)> &value)
{
    callbackValueChange = value;
}
