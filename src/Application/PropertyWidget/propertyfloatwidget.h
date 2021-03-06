#ifndef PROPERTYFLOATWIDGET_H
#define PROPERTYFLOATWIDGET_H

#include <QWidget>
#include <QDoubleSpinBox>
#include "../../export/Core/PropertyControl/propertyfloatcontrol.h"

namespace Ui {
class PropertyFloatWidget;
}

class PropertyFloatWidget : public QWidget, public PropertyFloatControl
{
    Q_OBJECT
public:
    explicit PropertyFloatWidget(QWidget *parent = nullptr);
    ~PropertyFloatWidget() override;
    void setName(const std::string &value) override;
    void setValue(float value) override;
    void setMin(float value) override;
    void setMax(float value) override;
    void setCallbackValueChange(const std::function<void (float)> &callback) override;

private:
    Ui::PropertyFloatWidget *ui;
    std::function<void (float)> callbackValueChange;
};

#endif // PROPERTYFLOATWIDGET_H
