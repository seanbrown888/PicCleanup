#include "stdafx.h"
#include "PictureDuplicateCleaner.h"

PictureDuplicateCleaner::PictureDuplicateCleaner(I_RecursiveFileListingProvider& fileListingProvider, I_FileOnDiskMover& diskMover)
: fileListingProvider_(fileListingProvider), diskMover_(diskMover)
{
}


PictureDuplicateCleaner::~PictureDuplicateCleaner()
{
}

void PictureDuplicateCleaner::cleanup(const std::string& directoryPath, const std::vector<std::string>& pictureFileExtensionsToClean)
{
}
