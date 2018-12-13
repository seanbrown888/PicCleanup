#include "stdafx.h"
#include "PictureDuplicateCleaner.h"

PictureDuplicateCleaner::PictureDuplicateCleaner(I_DuplicateFileFinder& fileDuplicateFinder, I_FileOnDiskMover& diskMover)
: fileDuplicateFinder_(fileDuplicateFinder), diskMover_(diskMover)
{
}


PictureDuplicateCleaner::~PictureDuplicateCleaner()
{
}

void PictureDuplicateCleaner::cleanup(const std::string& directoryPath, const std::vector<std::string>& pictureFileExtensionsToClean)
{
}
