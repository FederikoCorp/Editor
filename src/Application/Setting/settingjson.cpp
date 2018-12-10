#include "settingjson.h"

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
        std::unique_ptr<GameObject> gameObject(new GameObject(name.toStdString(), sceneObject));

        if(!gameObjectJson["limit"].isNull())
        {
            SceneObject *sceneObject = gameObject->getSceneObject().get();
            limitGameObject[sceneObject] = static_cast<uint>(gameObjectJson["limit"].toInt());
        }
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

std::vector<std::unique_ptr<GameObject> >& SettingJson::getAvailableGameObjects()
{
    return availableGameObject;
}

std::unordered_map<SceneObject*, uint> SettingJson::getLimitGameObject()
{
    return limitGameObject;
}

GameObject *SettingJson::getGameObjectByName(const std::string &name)
{
    auto it = nameToGameObject.find(name);
    if(it != nameToGameObject.end())
        return it->second;
    return nullptr;
}
