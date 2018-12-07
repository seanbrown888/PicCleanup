#pragma once

#include "I_PictureFileDiskCleaner.h"
#include "I_RecursiveFileListingProvider.h"

class PicCleanupBL
{
public:
    PicCleanupBL(I_RecursiveFileListingProvider& fileListingProvider, I_PictureFileDiskCleaner& diskCleaner);
    ~PicCleanupBL();

private:
    I_RecursiveFileListingProvider& fileListingProvider_;
    I_PictureFileDiskCleaner& diskCleaner_;
};

