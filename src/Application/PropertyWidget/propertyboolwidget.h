#ifndef PROPERTYBOOLWIDGET_H
#define PROPERTYBOOLWIDGET_H

#include <QWidget>
#include <QCheckBox>
#include <QDebug>
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

private:
    Ui::PropertyBoolWidget *ui;
};

#endif // PROPERTYBOOLWIDGET_H
