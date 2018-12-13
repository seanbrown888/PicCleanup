#pragma once

#include <string>
#include <vector>

#include "I_PictureCleaner.h"
#include "I_RecursiveFileListingProvider.h"
#include "I_FileOnDiskMover.h"

class PictureDuplicateCleaner : public I_PictureCleaner
{
public:
    PictureDuplicateCleaner(I_RecursiveFileListingProvider& fileListingProvider, I_FileOnDiskMover& diskMover);
    ~PictureDuplicateCleaner();

    void cleanup(const std::string& directoryPath, const std::vector<std::string>& pictureFileExtensionsToClean);

private:
    I_RecursiveFileListingProvider& fileListingProvider_;
    I_FileOnDiskMover& diskMover_;
};

