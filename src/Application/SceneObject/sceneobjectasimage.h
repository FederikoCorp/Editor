#ifndef SCENEOBJECTASIMAGE_H
#define SCENEOBJECTASIMAGE_H

#include <string>
#include "../../export/Core/SceneObject/sceneobject.h"

class SceneObjectAsImage : public SceneObject
{
public:
    SceneObjectAsImage(const std::string &imageFileName);
    std::string getImageFileName() const;

private:
    std::string imageFileName;
};

#endif // SCENEOBJECTASIMAGE_H
