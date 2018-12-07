#pragma once

#include <vector>
#include <string>

class I_PictureFileDiskCleaner
{
public:
    I_PictureFileDiskCleaner() = default;
    virtual ~I_PictureFileDiskCleaner() = default;

    virtual void moveFile(const std::string& oldFilenameWithPath, const std::string& newFileNameWithPath) = 0;
};

