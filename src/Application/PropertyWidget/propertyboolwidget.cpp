#include "propertyboolwidget.h"
#include "ui_propertyboolwidget.h"

PropertyBoolWidget::PropertyBoolWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PropertyBoolWidget)
{
    ui->setupUi(this);
    connect(ui->propertyCheckBox, &QCheckBox::stateChanged, this, [this](int state) {
        if(callbackValueChange)
            callbackValueChange(state != 0);
    });
}

PropertyBoolWidget::~PropertyBoolWidget()
{
    delete ui;
}

void PropertyBoolWidget::setName(const std::string &value)
{
    ui->propertyCheckBox->setText(value.c_str());
}

void PropertyBoolWidget::setValue(bool value)
{
    if(value)
        ui->propertyCheckBox->setCheckState(Qt::CheckState::Checked);
    else
        ui->propertyCheckBox->setCheckState(Qt::CheckState::Unchecked);
}
