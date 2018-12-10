#include "MainWindow/mainwindow.h"
#include <QApplication>
#include "../../export/Core/core.h"
#include "Setting/settingjson.h"
#include "Storage/storagejson.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SettingJson setting("setting.json");
    StorageJson storage;
    MainWindow w;
    Core core(&w, &setting, &storage);

    w.show();

    return a.exec();
}
