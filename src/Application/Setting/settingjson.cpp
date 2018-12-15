#include "settingjson.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QFile>

#include "SceneObject/sceneobjectasimage.h"
#include "../../export/Core/gameobject.h"
#include "../../export/Core/Property/propertybool.h"
#include "../../export/Core/Property/propertyfloat.h"
#include "../../export/Core/Property/propertyint.h"
#include "../../export/Core/Property/propertyliststate.h"

SettingJson::SettingJson(const std::string &fileName)
{
    QFile file(fileName.c_str());
    if(!file.open(QIODevice::ReadOnly))
        return;

    QJsonDocument document(QJsonDocument::fromJson(file.readAll()));

    QJsonObject json = document.object();

    QString imageFileName;
    for(QString name : json.keys())
    {
        imageFileName = "";
        QJsonObject gameObjectJson = json[name].toObject();
        if(!gameObjectJson["image"].isNull())
            imageFileName = gameObjectJson["image"].toString();

        std::shared_ptr<SceneObject> sceneObject(new SceneObjectAsImage(imageFileName.toStdString()));
        std::unique_ptr<GameObject> gameObject;

        if(!gameObjectJson["limit"].isNull())
        {
            uint limit = static_cast<uint>(gameObjectJson["limit"].toInt());
            //limit + 1, потому что 1 объект будет лежать не на сцене, а в availableGameObjects
            gameObject.reset(new GameObject(name.toStdString(), sceneObject, limit + 1));
        }
        else
            gameObject.reset(new GameObject(name.toStdString(), sceneObject));


        if(!gameObjectJson["property"].isNull())
        {
            QJsonObject propertiesJson = gameObjectJson["property"].toObject();
            for(QString name : propertiesJson.keys())
            {
                if(propertiesJson[name].isArray())
                {
                    QJsonArray stateArray = propertiesJson[name].toArray();
                    std::unique_ptr<PropertyListState> listState(new PropertyListState(name.toStdString()));

                    for(int i = 0; i < stateArray.count(); ++i)
                    {
                        listState->addState(stateArray[i].toString().toStdString());
                    }

                    if(stateArray.size() > 0)
                        gameObject->addProperty(std::move(listState));
                }
                else
                {
                    QJsonObject propertyJson = propertiesJson[name].toObject();

                    if(propertyJson["type"].isNull())
                        continue;
                    if(propertyJson["type"].isString())
                    {
                        QString type = propertyJson["type"].toString();
                        if(type == "float")
                        {
                            std::unique_ptr<PropertyFloat> property = std::make_unique<PropertyFloat>(name.toStdString());
                            if(!propertyJson["min"].isNull())
                                property->setMin(static_cast<float>(propertyJson["min"].toDouble()));
                            if(!propertyJson["max"].isNull())
                                property->setMax(static_cast<float>(propertyJson["max"].toDouble()));
                            gameObject->addProperty(std::move(property));
                        }
                        else if(type == "int")
                        {
                            std::unique_ptr<PropertyInt> property = std::make_unique<PropertyInt>(name.toStdString());
                            if(!propertyJson["min"].isNull())
                                property->setMin(propertyJson["min"].toInt());
                            if(!propertyJson["max"].isNull())
                                property->setMax(propertyJson["max"].toInt());
                            gameObject->addProperty(std::move(property));

                        }
                        else if(type == "bool")
                        {
                            gameObject->addProperty(std::make_unique<PropertyBool>(name.toStdString()));
                        }
                    }
                }
            }
        }
        nameToGameObject[gameObject->getName()] = gameObject.get();
        availableGameObject.push_back(std::move(gameObject));
    }

    file.close();
}

SettingJson::~SettingJson() = default;

std::vector<std::unique_ptr<GameObject> >& SettingJson::getAvailableGameObjects()
{
    return availableGameObject;
}

GameObject *SettingJson::getGameObjectByName(const std::string &name)
{
    auto it = nameToGameObject.find(name);
    if(it != nameToGameObject.end())
        return it->second;
    return nullptr;
}
