#pragma once

#include <vector>
#include "PictureFileInfo.h"

class I_RecursiveFileListingProvider
{
public:
    I_RecursiveFileListingProvider() = default;
    virtual ~I_RecursiveFileListingProvider() = default;

    virtual std::vector<PictureFileInfo> filesInDirectory(const std::string& directoryPath, const std::vector<std::string>& fileExtensionsToInclude) = 0;
};

