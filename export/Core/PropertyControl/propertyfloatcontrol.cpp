#include "propertyfloatcontrol.h"

void PropertyFloatControl::setCallbackValueChange(const std::function<void (float)> &value)
{
    callbackValueChange = value;
}
