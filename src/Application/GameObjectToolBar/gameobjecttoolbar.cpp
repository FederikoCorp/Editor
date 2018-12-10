#include "gameobjecttoolbar.h"
#include "ui_gameobjecttoolbar.h"

GameObjectToolBar::GameObjectToolBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameObjectToolBar)
{
    ui->setupUi(this);
    connect(ui->eraserPushButton, &QPushButton::clicked, this, [this](){
        if(!toolErase)
            return;
        currentTool = toolErase.get();
    });
    connect(ui->selectPushButton, &QPushButton::clicked, this, [this](){
        if(!toolSelect)
            return;
        currentTool = toolSelect.get();
    });
    connect(ui->gameObjectListWidget, &QListWidget::itemClicked, this, [this]()
    {
        if(!toolCreate)
            return;
        currentTool = toolCreate.get();
        toolCreate->setIndex(static_cast<uint>(ui->gameObjectListWidget->currentRow()));
    });
}

GameObjectToolBar::~GameObjectToolBar()
{
    delete ui;
}

void GameObjectToolBar::addGameObject(const QString &fileName, const QString &name)
{
    QListWidgetItem *item = new QListWidgetItem(QIcon(fileName), name);
    ui->gameObjectListWidget->addItem(item);
}

void GameObjectToolBar::setAvailableGameObject(int index, bool available)
{
    if(!available)
    {
        ui->gameObjectListWidget->item(index)->setBackgroundColor(QColor(150,10,10));
        ui->gameObjectListWidget->item(index)->setTextColor(QColor(200,200,200));
    }
    else
    {
        ui->gameObjectListWidget->item(index)->setBackgroundColor(QColor(255,255,255));
        ui->gameObjectListWidget->item(index)->setTextColor(QColor(0,0,0));
    }
}

Tool *GameObjectToolBar::getCurrentTool() const
{
    return currentTool;
}

void GameObjectToolBar::createToolCreate(const std::function<void (uint, uint, uint)> &func)
{
    toolCreate = std::make_unique<ToolCreate>(func);
}

void GameObjectToolBar::createToolErase(const std::function<void (uint, uint)> &func)
{
    toolErase = std::make_unique<ToolErase>(func);
}

void GameObjectToolBar::createToolSelect(const std::function<void (uint, uint)> &func)
{
    toolSelect = std::make_unique<ToolSelect>(func);
}

