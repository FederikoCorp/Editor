#ifndef PROPERTYBOOLWIDGET_H
#define PROPERTYBOOLWIDGET_H

#include <QWidget>
#include <QCheckBox>
#include "../../export/Core/PropertyControl/propertyboolcontrol.h"

namespace Ui {
class PropertyBoolWidget;
}

class PropertyBoolWidget : public QWidget, public PropertyBoolControl
{
    Q_OBJECT

public:
    explicit PropertyBoolWidget(QWidget *parent = nullptr);
    ~PropertyBoolWidget() override;
    void setName(const std::string &value) override;
    void setValue(bool value) override;
    void setCallbackValueChange(const std::function<void (bool)> &callback) override;

private:
    Ui::PropertyBoolWidget *ui;
    std::function<void (bool)> callbackValueChange;
};

#endif // PROPERTYBOOLWIDGET_H
