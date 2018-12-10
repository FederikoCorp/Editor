#-------------------------------------------------
#
# Project created by QtCreator 2018-12-08T13:04:48
#
#-------------------------------------------------

QT       -= core gui

TARGET = Core
TEMPLATE = lib

DEFINES += CORE_LIBRARY

DEFINES += QT_DEPRECATED_WARNINGS

include(../../common.pri)
include(../../lib.pri)

SOURCES += \
        core.cpp \
    gameobject.cpp \
    Property\property.cpp \
    scene.cpp \
    Property/propertybool.cpp \
    Property/propertyint.cpp \
    Property/propertyliststate.cpp \
    Property/propertyfloat.cpp \
    $$PROJECT_ROOT_PATH/Export/Core/PropertyControl/propertyboolcontrol.cpp \
    $$PROJECT_ROOT_PATH/Export/Core/PropertyControl/propertyfloatcontrol.cpp \
    $$PROJECT_ROOT_PATH/Export/Core/PropertyControl/propertyintcontrol.cpp \
    $$PROJECT_ROOT_PATH/Export/Core/PropertyControl/propertyliststatecontrol.cpp


HEADERS += \
        $$PROJECT_ROOT_PATH/Export/Core/core.h \
    gameobject.h \
    scene.h \
    $$PROJECT_ROOT_PATH/Export/Core/SceneObject/sceneobject.h \
    $$PROJECT_ROOT_PATH/Export/Core/Property\property.h \
    $$PROJECT_ROOT_PATH/Export/Core/Property/propertybool.h \
    $$PROJECT_ROOT_PATH/Export/Core/Property/propertyint.h \
    $$PROJECT_ROOT_PATH/Export/Core/Property/propertyliststate.h \
    $$PROJECT_ROOT_PATH/Export/Core/Property/propertyfloat.h \
    $$PROJECT_ROOT_PATH/Export/Core/Gateway/userinterfacegateway.h \
    $$PROJECT_ROOT_PATH/Export/Core/Gateway/settinggateway.h \
    $$PROJECT_ROOT_PATH/Export/Core/PropertyControl/propertycontrol.h \
    $$PROJECT_ROOT_PATH/Export/Core/PropertyControl/propertyboolcontrol.h \
    $$PROJECT_ROOT_PATH/Export/Core/PropertyControl/propertyfloatcontrol.h \
    $$PROJECT_ROOT_PATH/Export/Core/PropertyControl/propertyintcontrol.h \
    $$PROJECT_ROOT_PATH/Export/Core/PropertyControl/propertyliststatecontrol.h \
    $$PROJECT_ROOT_PATH/Export/Core/Gateway/downloadgateway.h \
    $$PROJECT_ROOT_PATH/Export/Core/StorageProperty/storageproperty.h \
    $$PROJECT_ROOT_PATH/Export/Core/StorageProperty/storagepropertyint.h \
    $$PROJECT_ROOT_PATH/Export/Core/StorageProperty/storagepropertyfloat.h \
    $$PROJECT_ROOT_PATH/Export/Core/StorageProperty/storagepropertybool.h \
    $$PROJECT_ROOT_PATH/Export/Core/StorageProperty/storagepropertyliststate.h \
    $$PROJECT_ROOT_PATH/Export/Core/Gateway/unloadgateway.h \
    ../../export/Core/StorageProperty/storagescene.h \
    ../../export/Core/StorageProperty/storagegameobject.h

