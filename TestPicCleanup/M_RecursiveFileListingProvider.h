#pragma once

#include <vector>
#include <gmock/gmock.h>

#include "../PicCleanupLib/I_RecursiveFileListingProvider.h"
#include "../PicCleanupLib/PictureFileInfo.h"

class M_RecursiveFileListingProvider : public I_RecursiveFileListingProvider
{
public:
    M_RecursiveFileListingProvider() = default;
    virtual ~M_RecursiveFileListingProvider() = default;

    MOCK_METHOD2(filesInDirectory, std::vector<PictureFileInfo>(const std::string& directoryPath, const std::vector<std::string>& fileExtensionsToInclude));
};


