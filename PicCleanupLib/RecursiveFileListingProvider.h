#pragma once
#include "I_RecursiveFileListingProvider.h"

class RecursiveFileListingProvider : public I_RecursiveFileListingProvider
{
public:
    RecursiveFileListingProvider();
    ~RecursiveFileListingProvider();

    std::vector<PictureFileInfo> filesInDirectory(const std::string& directoryPath, const std::vector<std::string>& fileExtensionsToInclude) override;

};

