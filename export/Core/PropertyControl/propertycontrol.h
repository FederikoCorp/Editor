#ifndef PROPERTYCONTROL_H
#define PROPERTYCONTROL_H

#include <functional>
#include <string>

class PropertyControl
{
public:
    PropertyControl() = default;
    virtual ~PropertyControl() = default;
    virtual void setName(const std::string &value) = 0;

protected:
    std::string name;
};

#endif // PROPERTYCONTROL_H
