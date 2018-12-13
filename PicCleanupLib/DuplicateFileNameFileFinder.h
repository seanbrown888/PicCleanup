#pragma once
#include "I_DuplicateFileFinder.h"

class DuplicateFileNameFileFinder : public I_DuplicateFileFinder
{
public:
    DuplicateFileNameFileFinder();
    ~DuplicateFileNameFileFinder();

    std::unordered_map<PictureFileInfo, std::vector<PictureFileInfo>> findDuplicateFiles(const std::string& directoryPath, const std::vector<std::string>& fileExtensions) override;
};

