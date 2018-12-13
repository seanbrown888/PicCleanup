#pragma once

#include "I_FileOnDiskMover.h"
#include "I_RecursiveFileListingProvider.h"
#include "PictureDuplicateCleaner.h"

class PicCleanupBL
{
public:
    PicCleanupBL(I_RecursiveFileListingProvider& fileListingProvider, I_FileOnDiskMover& diskMover);
    ~PicCleanupBL();

    I_PictureCleaner& cleaner();

private:
    I_RecursiveFileListingProvider& fileListingProvider_;
    I_FileOnDiskMover& diskMover_;

    PictureDuplicateCleaner cleaner_;
};

