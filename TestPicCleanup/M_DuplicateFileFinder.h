#pragma once

#include <vector>
#include <gmock/gmock.h>

#include "../PicCleanupLib/I_DuplicateFileFinder.h"

class M_DuplicateFileFinder : public I_DuplicateFileFinder
{
public:
    M_DuplicateFileFinder() = default;
    virtual ~M_DuplicateFileFinder() = default;

    MOCK_METHOD2(findDuplicateFiles, std::unordered_map<PictureFileInfo, std::vector<PictureFileInfo>>(const std::string& directoryPath, const std::vector<std::string>& fileExtensions));
};