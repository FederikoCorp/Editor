#include "sceneobjectasimage.h"

SceneObjectAsImage::SceneObjectAsImage(const std::string &imageFileName) : imageFileName(imageFileName)
{

}

std::string SceneObjectAsImage::getImageFileName() const
{
    return imageFileName;
}
