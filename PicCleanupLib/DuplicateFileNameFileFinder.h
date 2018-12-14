#pragma once
#include "I_DuplicateFileFinder.h"
#include "I_RecursiveFileListingProvider.h"

class DuplicateFileNameFileFinder : public I_DuplicateFileFinder
{
public:
    DuplicateFileNameFileFinder(I_RecursiveFileListingProvider& fileListingProvider);
    ~DuplicateFileNameFileFinder();

    std::unordered_map<PictureFileInfo, std::vector<PictureFileInfo>> findDuplicateFiles(const std::string& directoryPath, const std::vector<std::string>& fileExtensions) override;

private:
    I_RecursiveFileListingProvider& fileListingProvider_;
};

