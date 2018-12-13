#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "PictureFileInfo.h"

class I_DuplicateFileFinder
{
public:
    I_DuplicateFileFinder() = default;
    virtual ~I_DuplicateFileFinder() = default;

    virtual std::unordered_map<PictureFileInfo, std::vector<PictureFileInfo>> findDuplicateFiles(const std::string& directoryPath, const std::vector<std::string>& fileExtensions) = 0;
};
