#pragma once

#include <vector>
#include "PictureFileInfo.h"

class I_PictureFileDiskCleaner
{
public:
    I_PictureFileDiskCleaner() = default;
    virtual ~I_PictureFileDiskCleaner() = default;

    virtual void movePictureToOriginals(const PictureFileInfo& pictureFile) = 0;
    virtual void movePictureToDuplicates(const PictureFileInfo& pcitureFile) = 0;
};

