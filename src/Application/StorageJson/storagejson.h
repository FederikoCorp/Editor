#ifndef STORAGEJSON_H
#define STORAGEJSON_H

#include <QJsonObject>

class StorageJson
{
public:
    StorageJson() = default;
    virtual ~StorageJson() = default;
    QJsonObject getJsonObject() const;

protected:
    QJsonObject jsonObject;
};

#endif // STORAGEJSON_H
