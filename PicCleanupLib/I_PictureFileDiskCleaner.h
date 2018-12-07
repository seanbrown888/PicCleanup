#pragma once

#include <vector>
#include <string>

class I_FileOnDiskDiskMover
{
public:
    I_FileOnDiskDiskMover() = default;
    virtual ~I_FileOnDiskDiskMover() = default;

    virtual void moveFile(const std::string& oldFilenameWithPath, const std::string& newFileNameWithPath) = 0;
};

