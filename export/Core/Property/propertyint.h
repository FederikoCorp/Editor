#ifndef PROPERTYINT_H
#define PROPERTYINT_H

#include <limits>
#include "property.h"

class PropertyInt : public Property
{
public:
    PropertyInt(const std::string &name);
    ~PropertyInt() override = default;

    void createPropertyControl(UserInterfaceGateway *userInterfaceGateWay) override;
    StoragePropertyPtr createStorageProperty(UnloadGateway *unloadGateway) override;
    PropertyPtr clone() override;

    int getValue() const;
    void setValue(int value);
    int getMin() const;
    int getMax() const;
    void setMin(int value);
    void setMax(int value);

private:
    int value = 0;
    int min = std::numeric_limits<int>::min();
    int max = std::numeric_limits<int>::max();
};

#endif // PROPERTYINT_H
