#pragma once

#include <vector>
#include <string>

class I_FileOnDiskMover
{
public:
    I_FileOnDiskMover() = default;
    virtual ~I_FileOnDiskMover() = default;

    virtual void moveFile(const std::string& oldFilenameWithPath, const std::string& newFileNameWithPath) = 0;
};

