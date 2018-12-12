#pragma once

#include <string>

struct PictureFileInfo
{
    PictureFileInfo(std::string nameOfFile, std::string pathOfParent)
    : filename(nameOfFile), parentPath(pathOfParent) {}

    inline bool operator==(const PictureFileInfo& rhs) const { return filename == rhs.filename && parentPath == rhs.parentPath;}
    inline bool operator!=(const PictureFileInfo& rhs) const { return !(operator==(rhs)); }

    std::string filename;
    std::string parentPath;
};