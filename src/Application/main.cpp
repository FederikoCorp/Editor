#include "MainWindow/mainwindow.h"
#include <QApplication>
#include "../../export/Core/core.h"
#include "Setting/settingjson.h"
#include "DownloaderFromJson/downloaderfromjson.h"
#include "UnloaderToJson/unloadertojson.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SettingJson setting("setting.json");
    DownloaderFromJson downloader(&setting);
    UnloaderToJson unloader;

    MainWindow w;
    Core core(&w, &setting, &downloader, &unloader);

    w.show();

    return a.exec();
}
