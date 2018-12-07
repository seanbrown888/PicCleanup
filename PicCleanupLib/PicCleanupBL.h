#pragma once

#include "I_PictureFileDiskCleaner.h"
#include "I_RecursiveFileListingProvider.h"

class PicCleanupBL
{
public:
    PicCleanupBL(I_RecursiveFileListingProvider& fileListingProvider, I_FileOnDiskDiskMover& diskCleaner);
    ~PicCleanupBL();

private:
    I_RecursiveFileListingProvider& fileListingProvider_;
    I_FileOnDiskDiskMover& diskCleaner_;
};

