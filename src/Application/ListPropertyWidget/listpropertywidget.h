#ifndef LISTPROPERTYWIDGET_H
#define LISTPROPERTYWIDGET_H

#include <QWidget>
#include <memory>
#include "PropertyWidget/propertyboolwidget.h"
#include "PropertyWidget/propertyfloatwidget.h"
#include "PropertyWidget/propertyintwidget.h"
#include "PropertyWidget/propertyliststatewidget.h"

namespace Ui {
class ListPropertyWidget;
}

class ListPropertyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ListPropertyWidget(QWidget *parent = nullptr);
    ~ListPropertyWidget();
    PropertyBoolWidget *createPropertyBoolWidget();
    PropertyFloatWidget *createPropertyFloatWidget();
    PropertyIntWidget *createPropertyIntWidget();
    PropertyListStateWidget *createPropertyListStateWidget();
    void destroyWidgets();

private:
    Ui::ListPropertyWidget *ui;
    std::vector<std::unique_ptr<PropertyControl>> controls;
};

#endif // LISTPROPERTYWIDGET_H
