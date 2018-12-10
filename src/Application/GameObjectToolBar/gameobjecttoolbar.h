#ifndef GAMEOBJECTTOOLBAR_H
#define GAMEOBJECTTOOLBAR_H

#include <QWidget>
#include <QImage>
#include <memory>
#include "Tool/toolcreate.h"
#include "Tool/toolerase.h"
#include "Tool/toolselect.h"

namespace Ui {
class GameObjectToolBar;
}

class GameObjectToolBar : public QWidget
{
    Q_OBJECT
public:
    explicit GameObjectToolBar(QWidget *parent = nullptr);
    ~GameObjectToolBar();
    void addGameObject(const QString &fileName, const QString &name);
    void setAvailableGameObject(int index, bool available);
    Tool *getCurrentTool() const;
    void createToolCreate(const std::function<void(uint x, uint y, uint index)> &func);
    void createToolErase(const std::function<void(uint x, uint y)> &func);
    void createToolSelect(const std::function<void(uint x, uint y)> &func);
signals:
    void changeCursor(QCursor cursor);

private:
    Ui::GameObjectToolBar *ui;
    std::unique_ptr<ToolCreate> toolCreate;
    std::unique_ptr<ToolErase> toolErase;
    std::unique_ptr<ToolSelect> toolSelect;
    Tool *currentTool = nullptr;

};

#endif // GAMEOBJECTTOOLBAR_H
