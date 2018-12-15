#include "downloaderfromjson.h"
#include "../Setting/settingjson.h"
#include "../../export/Core/scene.h"
#include "../../export/Core/gameobject.h"
#include "../../export/Core/Property/propertyint.h"
#include "../../export/Core/Property/propertybool.h"
#include "../../export/Core/Property/propertyfloat.h"
#include "../../export/Core/Property/propertyliststate.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

DownloaderFromJson::DownloaderFromJson(SettingJson *settingJson) : settingJson(settingJson)
{

}

std::unique_ptr<Scene> DownloaderFromJson::loadScene(const std::string &fileName)
{
    if(settingJson == nullptr)
        return nullptr;

    QFile fileMap(fileName.c_str());
    if(!fileMap.open(QIODevice::ReadOnly))
        return nullptr;

    QJsonDocument documentMap(QJsonDocument::fromJson((fileMap.readAll())));
    QJsonObject jsonMap = documentMap.object();

    if(jsonMap["width"].isNull() || jsonMap["height"].isNull())
    {
        fileMap.close();
        return nullptr;
    }
    uint width = toUint(jsonMap["width"].toInt());
    uint height = toUint(jsonMap["height"].toInt());
    if(width >= 1000 || height >= 1000)
    {
        fileMap.close();
        return nullptr;
    }

    std::unique_ptr<Scene> scene = std::make_unique<Scene>(width,height);

    if(!loadGameObject(jsonMap, scene.get()))
    {
        fileMap.close();
        return nullptr;
    }

    fileMap.close();
    return scene;
}

void DownloaderFromJson::loadProperty(QJsonArray jsonPropertyArray, GameObject *gameObject)
{
    for(int i = 0; i < jsonPropertyArray.count(); ++i)
    {
        QJsonObject jsonProperty = jsonPropertyArray[i].toObject();
        if(toUint(i) >= gameObject->getCountProperty())
            continue;

        if(!jsonProperty["int"].isNull())
        {
            PropertyInt *propertyInt = dynamic_cast<PropertyInt*>(gameObject->getProperty(toUint(i)));
            if(propertyInt == nullptr)
                continue;
            propertyInt->setValue(jsonProperty["int"].toInt());
        }
        else if (!jsonProperty["float"].isNull())
        {
            PropertyFloat *propertyFloat = dynamic_cast<PropertyFloat*>(gameObject->getProperty(toUint(i)));
            if(propertyFloat == nullptr)
                continue;
            propertyFloat->setValue(static_cast<float>(jsonProperty["float"].toDouble()));
        }
        else if (!jsonProperty["bool"].isNull())
        {
            PropertyBool *propertyBool = dynamic_cast<PropertyBool*>(gameObject->getProperty(toUint(i)));
            if(propertyBool == nullptr)
                continue;
            propertyBool->setValue(jsonProperty["bool"].toBool());
        }
        else if (!jsonProperty["list"].isNull())
        {
            PropertyListState *propertyListState = dynamic_cast<PropertyListState*>(gameObject->getProperty(toUint(i)));
            if(propertyListState == nullptr)
                continue;
            propertyListState->setCurrentState(static_cast<uint>(jsonProperty["list"].toInt()));
        }
    }
}

bool DownloaderFromJson::loadGameObject(QJsonObject jsonMap, Scene *scene)
{
    if(jsonMap["objects"].isNull() || !jsonMap["objects"].isArray())
        return false;
    QJsonArray jsonArrayObject = jsonMap["objects"].toArray();
    for(int i = 0; i < jsonArrayObject.count(); ++i)
    {
        QJsonObject jsonObject = jsonArrayObject[i].toObject();
        GameObject *prototype = settingJson->getGameObjectByName(jsonObject["object"].toString().toStdString());
        if(prototype == nullptr || jsonObject["x"].isNull() || jsonObject["y"].isNull())
            continue;

        uint x = toUint(jsonObject["x"].toInt());
        uint y = toUint(jsonObject["y"].toInt());
        if(x >= scene->getWidth() || y >= scene->getHeight())
            continue;

        if(scene->isGameObject(x, y))
            continue;

        std::unique_ptr<GameObject> gameObject = prototype->clone();
        if(!gameObject)
            continue;
        gameObject->setPosition(x, y);

        if(!jsonObject["property"].isNull() && jsonObject["property"].isArray())
        {
            QJsonArray jsonPropertyArray = jsonObject["property"].toArray();
            loadProperty(jsonPropertyArray, gameObject.get());
        }

        scene->addGameObject(std::move(gameObject));
    }
    return true;
}
