#ifndef PROPERTYINTWIDGET_H
#define PROPERTYINTWIDGET_H

#include <QWidget>
#include <QSpinBox>
#include "../../export/Core/PropertyControl/propertyintcontrol.h"

namespace Ui {
class PropertyIntWidget;
}

class PropertyIntWidget : public QWidget, public PropertyIntControl
{
    Q_OBJECT

public:
    explicit PropertyIntWidget(QWidget *parent = nullptr);
    ~PropertyIntWidget() override;
    void setName(const std::string &value) override;
    void setValue(int value) override;
    void setMin(int value) override;
    void setMax(int value) override;
    void setCallbackValueChange(const std::function<void (int)> &callback) override;

private:
    Ui::PropertyIntWidget *ui;
    std::function<void (int)> callbackValueChange;
};

#endif // PROPERTYINTWIDGET_H
