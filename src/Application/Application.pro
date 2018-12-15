#-------------------------------------------------
#
# Project created by QtCreator 2018-12-08T13:03:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Application
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

include(../../common.pri)
include(../../app.pri)

LIBS += "$$PROJECT_ROOT_PATH/lib/Core.dll"

SOURCES += \
        main.cpp \
        MainWindow/mainwindow.cpp \
        SceneObject/sceneobjectasimage.cpp \
        GameObjectToolBar/gameobjecttoolbar.cpp \
        PropertyWidget/propertyboolwidget.cpp \
        PropertyWidget/propertyfloatwidget.cpp \
        PropertyWidget/propertyintwidget.cpp \
        PropertyWidget/propertyliststatewidget.cpp \
        ListPropertyWidget/listpropertywidget.cpp \
        Tool/toolcreate.cpp \
        Tool/toolselect.cpp \
        Tool/toolerase.cpp \
        Setting/settingjson.cpp \
        DownloaderFromJson/downloaderfromjson.cpp \
        UnloaderToJson/unloadertojson.cpp \
        StorageJson/storagepropertyintjson.cpp \
        StorageJson/storagepropertybooljson.cpp \
        StorageJson/storagepropertyfloatjson.cpp \
        StorageJson/storagepropertyliststatejson.cpp \
        StorageJson/storagegameobjectjson.cpp \
        StorageJson/storagescenejson.cpp \
        StorageJson/storagejson.cpp

HEADERS += \
        MainWindow/mainwindow.h \
        $$PROJECT_ROOT_PATH/Export/Core/core.h \
        $$PROJECT_ROOT_PATH/Export/Core/SceneObject/sceneobject.h \
        $$PROJECT_ROOT_PATH/Export/Core/Gateway/userinterfacegateway.h \
        $$PROJECT_ROOT_PATH/Export/Core/Gateway/settinggateway.h \
        $$PROJECT_ROOT_PATH/Export/Core/PropertyControl/propertyboolcontrol.h \
        $$PROJECT_ROOT_PATH/Export/Core/PropertyControl/propertyfloatcontrol.h \
        $$PROJECT_ROOT_PATH/Export/Core/PropertyControl/propertyintcontrol.h \
        $$PROJECT_ROOT_PATH/Export/Core/PropertyControl/propertyliststatecontrol.h \
        $$PROJECT_ROOT_PATH/Export/Core/Property/property.h \
        $$PROJECT_ROOT_PATH/Export/Core/Property/propertybool.h \
        $$PROJECT_ROOT_PATH/Export/Core/Property/propertyint.h \
        $$PROJECT_ROOT_PATH/Export/Core/Property/propertyliststate.h \
        $$PROJECT_ROOT_PATH/Export/Core/Property/propertyfloat.h \
        $$PROJECT_ROOT_PATH/Export/Core/StorageProperty/storagescene.h \
        $$PROJECT_ROOT_PATH/Export/Core/StorageProperty/storagegameobject.h \
        $$PROJECT_ROOT_PATH/Export/Core/StorageProperty/storagepropertybool.h \
        $$PROJECT_ROOT_PATH/Export/Core/StorageProperty/storagepropertyfloat.h \
        $$PROJECT_ROOT_PATH/Export/Core/StorageProperty/storagepropertyint.h \
        $$PROJECT_ROOT_PATH/Export/Core/StorageProperty/storagepropertyliststate.h \
        SceneObject/sceneobjectasimage.h \
        GameObjectToolBar/gameobjecttoolbar.h \
        PropertyWidget/propertyboolwidget.h \
        PropertyWidget/propertyfloatwidget.h \
        PropertyWidget/propertyintwidget.h \
        PropertyWidget/propertyliststatewidget.h \
        ListPropertyWidget/listpropertywidget.h \
        Tool/tool.h \
        Tool/toolcreate.h \
        Tool/toolselect.h \
        Tool/toolerase.h \
        Setting/settingjson.h \
        DownloaderFromJson/downloaderfromjson.h \
        UnloaderToJson/unloadertojson.h \
        StorageJson/storagepropertyintjson.h \
        StorageJson/storagepropertybooljson.h \
        StorageJson/storagepropertyfloatjson.h \
        StorageJson/storagepropertyliststatejson.h \
        StorageJson/storagegameobjectjson.h \
        StorageJson/storagescenejson.h \
        StorageJson/storagejson.h

FORMS += \
        MainWindow/mainwindow.ui \
        GameObjectToolBar/gameobjecttoolbar.ui \
        PropertyWidget/propertyboolwidget.ui \
        PropertyWidget/propertyfloatwidget.ui \
        PropertyWidget/propertyintwidget.ui \
        PropertyWidget/propertyliststatewidget.ui \
        ListPropertyWidget/listpropertywidget.ui

RESOURCES += \
    ../../resource/resource.qrc

DISTFILES +=
