#include "stdafx.h"
#include "DuplicateFileNameFileFinder.h"


DuplicateFileNameFileFinder::DuplicateFileNameFileFinder()
{
}


DuplicateFileNameFileFinder::~DuplicateFileNameFileFinder()
{
}

std::unordered_map<PictureFileInfo, std::vector<PictureFileInfo>> DuplicateFileNameFileFinder::findDuplicateFiles(const std::string & directoryPath, const std::vector<std::string>& fileExtensions)
{
    return std::unordered_map<PictureFileInfo, std::vector<PictureFileInfo>>();
}
