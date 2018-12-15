#include "propertyliststatewidget.h"
#include "ui_propertyliststatewidget.h"

PropertyListStateWidget::PropertyListStateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PropertyListStateWidget)
{
    ui->setupUi(this);
    connect(ui->comboBox, qOverload<int>(&QComboBox::activated), this, [this](int index){
        if(callbackValueChange)
            callbackValueChange(static_cast<unsigned int>(index));
    });
}

PropertyListStateWidget::~PropertyListStateWidget()
{
    delete ui;
}

void PropertyListStateWidget::setName(const std::string &value)
{
    ui->propertyNameLabel->setText(value.c_str());
}

void PropertyListStateWidget::setValue(unsigned int value)
{
    ui->comboBox->setCurrentIndex(static_cast<int>(value));
}

void PropertyListStateWidget::addState(const std::string &state)
{
    ui->comboBox->addItem(state.c_str());
}

void PropertyListStateWidget::setCallbackValueChange(const std::function<void (unsigned int)> &callback)
{
    callbackValueChange = callback;
}
