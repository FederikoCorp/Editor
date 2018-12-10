#include "propertyliststatecontrol.h"

void PropertyListStateControl::setCallbackValueChange(const std::function<void (unsigned int)> &value)
{
    callbackValueChange = value;
}
