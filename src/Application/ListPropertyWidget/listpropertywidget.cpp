#include "listpropertywidget.h"
#include "ui_listpropertywidget.h"

ListPropertyWidget::ListPropertyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListPropertyWidget)
{
    ui->setupUi(this);
}

ListPropertyWidget::~ListPropertyWidget()
{
    delete ui;
}

PropertyBoolWidget *ListPropertyWidget::createPropertyBoolWidget()
{
    PropertyBoolWidget *widget = new PropertyBoolWidget(this);
    controls.emplace_back(widget);
    ui->contentLayout->insertWidget(static_cast<int>(0), widget);
    return widget;
}

PropertyFloatWidget *ListPropertyWidget::createPropertyFloatWidget()
{
    PropertyFloatWidget *widget = new PropertyFloatWidget(this);
    controls.emplace_back(widget);
    ui->contentLayout->insertWidget(static_cast<int>(0), widget);
    return widget;
}

PropertyIntWidget *ListPropertyWidget::createPropertyIntWidget()
{
    PropertyIntWidget *widget = new PropertyIntWidget(this);
    controls.emplace_back(widget);
    ui->contentLayout->insertWidget(static_cast<int>(0), widget);
    return widget;
}

PropertyListStateWidget *ListPropertyWidget::createPropertyListStateWidget()
{
    PropertyListStateWidget *widget = new PropertyListStateWidget(this);
    controls.emplace_back(widget);
    ui->contentLayout->insertWidget(static_cast<int>(0), widget);
    return widget;
}

void ListPropertyWidget::destroyWidgets()
{
    controls.clear();
}
