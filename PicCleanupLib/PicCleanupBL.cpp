#include "stdafx.h"
#include "PicCleanupBL.h"

PicCleanupBL::PicCleanupBL(I_RecursiveFileListingProvider& fileListingProvider, I_FileOnDiskMover& diskMover)
: fileListingProvider_(fileListingProvider), diskMover_(diskMover), cleaner_(fileListingProvider_, diskMover_)
{
}

PicCleanupBL::~PicCleanupBL()
{
}

I_PictureCleaner & PicCleanupBL::cleaner()
{
    return cleaner_;
}
