#include "stdafx.h"
#include "PicCleanupBL.h"

PicCleanupBL::PicCleanupBL(I_RecursiveFileListingProvider& fileListingProvider, I_FileOnDiskMover& diskCleaner)
: fileListingProvider_(fileListingProvider), diskCleaner_(diskCleaner)
{
}

PicCleanupBL::~PicCleanupBL()
{
}

I_PictureCleaner & PicCleanupBL::cleaner()
{
    return cleaner_;
}
