#pragma once

#include <string>

struct PictureFileInfo
{
    PictureFileInfo(std::string nameOfFile, std::string pathOfParent)
    : filename(nameOfFile), parentPath(pathOfParent) {}

    std::string filename;
    std::string parentPath;
};