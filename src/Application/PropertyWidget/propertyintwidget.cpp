#include "propertyintwidget.h"
#include "ui_propertyintwidget.h"

PropertyIntWidget::PropertyIntWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PropertyIntWidget)
{
    ui->setupUi(this);
    connect(ui->spinBox, qOverload<int>(&QSpinBox::valueChanged), this, [this](int value){
        if(callbackValueChange)
            callbackValueChange(value);
    });
}

PropertyIntWidget::~PropertyIntWidget()
{
    delete ui;
}

void PropertyIntWidget::setName(const std::string &value)
{
    ui->propertyNameLabel->setText(value.c_str());
}

void PropertyIntWidget::setValue(int value)
{
    ui->spinBox->setValue(value);
}

void PropertyIntWidget::setMin(int value)
{
    ui->spinBox->setMinimum(value);
}

void PropertyIntWidget::setMax(int value)
{
    ui->spinBox->setMaximum(value);
}
