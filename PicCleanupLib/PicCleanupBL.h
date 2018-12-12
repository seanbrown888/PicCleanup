#pragma once

#include "I_FileOnDiskMover.h"
#include "I_RecursiveFileListingProvider.h"

class PicCleanupBL
{
public:
    PicCleanupBL(I_RecursiveFileListingProvider& fileListingProvider, I_FileOnDiskMover& diskCleaner);
    ~PicCleanupBL();

private:
    I_RecursiveFileListingProvider& fileListingProvider_;
    I_FileOnDiskMover& diskCleaner_;
};

