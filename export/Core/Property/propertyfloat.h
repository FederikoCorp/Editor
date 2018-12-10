#ifndef PROPERTYFLOAT_H
#define PROPERTYFLOAT_H

#include <limits>
#include "property.h"

class PropertyFloat : public Property
{
public:
    PropertyFloat(const std::string &name);
    ~PropertyFloat() override = default;

    void createPropertyControl(UserInterfaceGateway *userInterfaceGateWay) override;
    std::unique_ptr<StorageProperty> getStorageProperty(UnloadGateway *unloadGateway) override;
    std::unique_ptr<Property> clone() override;

    float getValue() const;
    void setValue(float value);
    float getMin() const;
    void setMin(float value);
    float getMax() const;
    void setMax(float value);

private:
    float value = 0;
    float min = std::numeric_limits<float>::min();
    float max = std::numeric_limits<float>::max();
};

#endif // PROPERTYFLOAT_H
