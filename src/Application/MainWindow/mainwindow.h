#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QFileDialog>
#include <QDebug>
#include "../../export/Core/Gateway/userinterfacegateway.h"
#include "SceneObject/sceneobjectasimage.h"
#include "GameObjectToolBar/gameobjecttoolbar.h"
#include "ListPropertyWidget/listpropertywidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public UserInterfaceGateway
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void exit() override;

    PropertyBoolControl *createPropertyBoolControl() override;
    PropertyFloatControl *createPropertyFloatControl() override;
    PropertyIntControl *createPropertyIntControl() override;
    PropertyListStateControl *createPropertyListStateControl() override;
    void destroyPropertyControls() override;

    void addSceneObject(std::shared_ptr<SceneObject> sceneObject, uint x, uint y) override;
    void selectSceneObject(uint x, uint y) override;
    void removeSceneObject(uint x, uint y) override;
    void createScene(uint width, uint height) override;
    void clearScene() override;

    void addGameObjectTool(std::shared_ptr<SceneObject> sceneObject, const std::string &name) override;
    void setAvailableGameObjectTool(uint index, bool available) override;

    void setCallbackAddGameObject(const std::function<void (uint x, uint y, uint index)> &value) override;
    void setCallbackRemoveGameObject(const std::function<void (uint x, uint y)> &value) override;
    void setCallbackSelectGameObject(const std::function<void (uint x,uint y)> &value) override;
    void setCallbackCreateScene(const std::function<void (uint width, uint height)> &value) override;
    void setCallbackOpenScene(const std::function<void (const std::string &fileName)> &value) override;
    void setCallbackSaveScene(const std::function<void (const std::string &fileName)> &value) override;
    void setCallbackExit(const std::function<void ()> &value) override;

private:
    bool eventFilter(QObject *watched, QEvent *event) override;
    inline int toPos(unsigned int value) { return static_cast<int>(value * itemSize); }

    Ui::MainWindow *ui;

    QGraphicsScene scene;
    QGraphicsRectItem cursor;
    const uint itemSize = 50;
    std::vector<std::unique_ptr<QGraphicsItem>> grid;
    std::vector<std::vector<std::unique_ptr<QGraphicsItem>>> items;

    std::function<void (uint width, uint height)> callbackCreateScene;
    std::function<void (const std::string &fileName)> callbackOpenScene;
    std::function<void (const std::string &fileName)> callbackSaveScene;
    std::function<void()> callbackExit;
};

#endif // MAINWINDOW_H
