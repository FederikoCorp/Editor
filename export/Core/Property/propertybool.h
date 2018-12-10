#ifndef PROPERTYBOOL_H
#define PROPERTYBOOL_H

#include "property.h"

class PropertyBool : public Property
{
public:
    PropertyBool(const std::string& name);
    ~PropertyBool() override = default;

    void createPropertyControl(UserInterfaceGateway *userInterfaceGateWay) override;
    std::unique_ptr<StorageProperty> getStorageProperty(UnloadGateway *unloadGateway) override;
    std::unique_ptr<Property> clone() override;

    bool getValue() const;
    void setValue(bool value);

private:
    bool value = false;
};

#endif // PROPERTYBOOL_H
