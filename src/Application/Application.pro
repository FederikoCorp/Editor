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
        $$PROJECT_ROOT_PATH/Export/Core/PropertyControl/propertyboolcontrol.cpp \
        $$PROJECT_ROOT_PATH/Export/Core/PropertyControl/propertyfloatcontrol.cpp \
        $$PROJECT_ROOT_PATH/Export/Core/PropertyControl/propertyintcontrol.cpp \
        $$PROJECT_ROOT_PATH/Export/Core/PropertyControl/propertyliststatecontrol.cpp \
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
        Storage/storagejson.cpp

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
        $$PROJECT_ROOT_PATH/Export/Core/Property\property.h \
        $$PROJECT_ROOT_PATH/Export/Core/Property/propertybool.h \
        $$PROJECT_ROOT_PATH/Export/Core/Property/propertyint.h \
        $$PROJECT_ROOT_PATH/Export/Core/Property/propertyliststate.h \
        $$PROJECT_ROOT_PATH/Export/Core/Property/propertyfloat.h \
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
        Storage/storagejson.h

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

DISTFILES += \
    ../../resource/eraser.png
