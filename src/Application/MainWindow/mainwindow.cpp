#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sceneView->setScene(&scene);
    setWindowState(Qt::WindowMaximized);

    cursor.setRect(5,5,40,40);
    cursor.setPen(QPen(QColor(10,240,10), 2));
    cursor.setZValue(1);

    scene.addItem(&cursor);

    scene.installEventFilter(this);
    connect(ui->actionCreateScene, &QAction::triggered, this, [this](){
        //По идее здесь должно появлятся диалоговое окно с настройками сцены, в которо указывается размер
        callbackCreateScene(30, 15);
    });
    connect(ui->actionOpenScene, &QAction::triggered, this, [this](){
        QString fileName = QFileDialog::getOpenFileName(this, "Открыть", "", "*.json");
        callbackOpenScene(fileName.toStdString());
    });
    connect(ui->actionSaveScene, &QAction::triggered, this, [this](){
        QString fileName = QFileDialog::getSaveFileName(this, "Сохранить", "", "*.json");
        callbackSaveScene(fileName.toStdString());
    });
    connect(ui->actionExit, &QAction::triggered, this, [=](){
        callbackExit();
    });
    connect(ui->gameObjectToolBar, &GameObjectToolBar::changeCursor, this, [this](QCursor cursor){
        ui->sceneView->setCursor(cursor);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exit()
{
    close();
}

PropertyBoolControl *MainWindow::createPropertyBoolControl()
{
    return ui->listPropertyWidget->createPropertyBoolWidget();
}

PropertyFloatControl *MainWindow::createPropertyFloatControl()
{
    return ui->listPropertyWidget->createPropertyFloatWidget();
}

PropertyIntControl *MainWindow::createPropertyIntControl()
{
    return ui->listPropertyWidget->createPropertyIntWidget();
}

PropertyListStateControl *MainWindow::createPropertyListStateControl()
{
    return ui->listPropertyWidget->createPropertyListStateWidget();
}

void MainWindow::destroyPropertyControls()
{
    ui->listPropertyWidget->destroyWidgets();
}

void MainWindow::addSceneObject(std::shared_ptr<SceneObject> sceneObject, uint x, uint y)
{
    SceneObjectAsImage *tempSceneObject = dynamic_cast<SceneObjectAsImage*>(sceneObject.get());

    QString path = QApplication::applicationDirPath() + "/" + tempSceneObject->getImageFileName().c_str();
    QImage image(path);
    if(image.isNull())
        return;
    image = image.scaled(static_cast<int>(itemSize), static_cast<int>(itemSize));

    std::unique_ptr<QGraphicsItem> ptr(scene.addPixmap(QPixmap::fromImage(image)));
    ptr->setPos(toPos(x), toPos(y));

    items[x][y] = std::move(ptr);
}

void MainWindow::selectSceneObject(uint x, uint y)
{
    cursor.setPos(toPos(x), toPos(y));
}

void MainWindow::removeSceneObject(uint x, uint y)
{
    scene.removeItem(items[x][y].get());
    items[x][y].reset(nullptr);
}

void MainWindow::createScene(uint width, uint height)
{
    grid.clear();
    items.clear();
    for(uint i = 0; i < width; ++i)
    {
        items.emplace_back(height);
        for(uint j = 0; j < height; ++j)
        {
            grid.emplace_back(scene.addRect(toPos(i),toPos(j), itemSize, itemSize, QPen(QColor(50,10,10),0.5)));
            grid.back()->setZValue(1);
        }
    }
}

void MainWindow::clearScene()
{
    items.clear();
    grid.clear();
}

void MainWindow::addGameObjectTool(std::shared_ptr<SceneObject> sceneObject, const std::string &name)
{
    SceneObjectAsImage *sceneObjectAsImage = dynamic_cast<SceneObjectAsImage*>(sceneObject.get());
    ui->gameObjectToolBar->addGameObject(sceneObjectAsImage->getImageFileName().c_str(), name.c_str());
}

void MainWindow::setAvailableGameObjectTool(uint index, bool available)
{
    ui->gameObjectToolBar->setAvailableGameObject(static_cast<int>(index), available);
}

void MainWindow::setCallbackAddGameObject(const std::function<void (uint, uint, uint)> &value)
{
    ui->gameObjectToolBar->createToolCreate(value);
}

void MainWindow::setCallbackRemoveGameObject(const std::function<void (uint, uint)> &value)
{
    ui->gameObjectToolBar->createToolErase(value);
}

void MainWindow::setCallbackSelectGameObject(const std::function<void (uint, uint)> &value)
{
    ui->gameObjectToolBar->createToolSelect(value);
}

void MainWindow::setCallbackCreateScene(const std::function<void (uint, uint)> &value)
{
    callbackCreateScene = value;
}

void MainWindow::setCallbackOpenScene(const std::function<void (const std::string &)> &value)
{
    callbackOpenScene = value;
}

void MainWindow::setCallbackSaveScene(const std::function<void (const std::string &)> &value)
{
    callbackSaveScene = value;
}

void MainWindow::setCallbackExit(const std::function<void ()> &value)
{
    callbackExit = value;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched != &scene || event->type() != QEvent::GraphicsSceneMousePress)
        return false;

    QGraphicsSceneMouseEvent *mouseEvent = dynamic_cast<QGraphicsSceneMouseEvent*>(event);
    if(mouseEvent == nullptr)
        return false;

    uint x = 0;
    uint y = 0;
    Tool *tool = ui->gameObjectToolBar->getCurrentTool();
    if(tool == nullptr)
        return false;

    if(mouseEvent->button() == Qt::LeftButton)
    {
        x = static_cast<uint>(mouseEvent->buttonDownScenePos(Qt::LeftButton).x()) / itemSize;
        y = static_cast<uint>(mouseEvent->buttonDownScenePos(Qt::LeftButton).y()) / itemSize;
        tool->action(x, y);
    }

    if(mouseEvent->button() == Qt::RightButton)
    {
        x = static_cast<uint>(mouseEvent->buttonDownScenePos(Qt::RightButton).x()) / itemSize;
        y = static_cast<uint>(mouseEvent->buttonDownScenePos(Qt::RightButton).y()) / itemSize;
        tool->action(x, y);
    }

    return true;
}
