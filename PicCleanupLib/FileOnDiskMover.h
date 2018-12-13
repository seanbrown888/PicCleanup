#pragma once
#include "I_FileOnDiskMover.h"

class FileOnDiskMover : public I_FileOnDiskMover
{
public:
    FileOnDiskMover();
    ~FileOnDiskMover();

    void moveFile(const std::string& oldFilenameWithPath, const std::string& newFileNameWithPath) override;
};

