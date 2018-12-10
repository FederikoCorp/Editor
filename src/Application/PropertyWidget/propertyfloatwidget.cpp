#include "propertyfloatwidget.h"
#include "ui_propertyfloatwidget.h"

PropertyFloatWidget::PropertyFloatWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PropertyFloatWidget)
{
    ui->setupUi(this);
    connect(ui->doubleSpinBox, qOverload<double>(&QDoubleSpinBox::valueChanged), this, [this](double value){
        if(callbackValueChange)
            callbackValueChange(static_cast<float>(value));
    });
}

PropertyFloatWidget::~PropertyFloatWidget()
{
    delete ui;
}

void PropertyFloatWidget::setName(const std::string &value)
{
    ui->propertyNameLabel->setText(value.c_str());
}

void PropertyFloatWidget::setValue(float value)
{
    ui->doubleSpinBox->setValue(static_cast<double>(value));
}

void PropertyFloatWidget::setMin(float value)
{
    ui->doubleSpinBox->setMinimum(static_cast<double>(value));
}

void PropertyFloatWidget::setMax(float value)
{
    ui->doubleSpinBox->setMaximum(static_cast<double>(value));
}
