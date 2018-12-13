#include "stdafx.h"
#include "FileOnDiskMover.h"

#include <filesystem>
#include <string>

namespace fs = std::experimental::filesystem;

FileOnDiskMover::FileOnDiskMover()
{
}


FileOnDiskMover::~FileOnDiskMover()
{
}

void FileOnDiskMover::moveFile(const std::string & oldFilenameWithPath, const std::string & newFileNameWithPath)
{
    fs::rename(oldFilenameWithPath, newFileNameWithPath);
}
