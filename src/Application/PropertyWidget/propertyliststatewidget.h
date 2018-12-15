#ifndef PROPERTYLISTSTATEWIDGET_H
#define PROPERTYLISTSTATEWIDGET_H

#include <QWidget>
#include <QComboBox>
#include "../../export/Core/PropertyControl/propertyliststatecontrol.h"

namespace Ui {
class PropertyListStateWidget;
}

class PropertyListStateWidget : public QWidget, public PropertyListStateControl
{
    Q_OBJECT

public:
    explicit PropertyListStateWidget(QWidget *parent = nullptr);
    ~PropertyListStateWidget() override;
    void setName(const std::string &value) override;
    void setValue(unsigned int value) override;
    void addState(const std::string &state) override;
    void setCallbackValueChange(const std::function<void (unsigned int)> &callback) override;

private:
    Ui::PropertyListStateWidget *ui;
    std::function<void(unsigned int)> callbackValueChange;
};

#endif // PROPERTYLISTSTATEWIDGET_H
