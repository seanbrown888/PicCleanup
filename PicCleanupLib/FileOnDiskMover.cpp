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
    std::error_code ec; // I don't seem to care about these errors yet, I just don't want the exception

    fs::path pathForMovedFile(newFileNameWithPath);
    if (!fs::exists(pathForMovedFile.parent_path()))
    {
        fs::create_directory(pathForMovedFile.parent_path(), ec);
    }
    fs::rename(oldFilenameWithPath, pathForMovedFile, ec);
}
