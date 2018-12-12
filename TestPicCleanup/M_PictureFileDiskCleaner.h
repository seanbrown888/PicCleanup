#pragma once

#include <vector>
#include <gmock/gmock.h>

#include "../PicCleanupLib/I_FileOnDiskMover.h"

class M_PictureFileDiskCleaner : public I_FileOnDiskMover
{
public:
    M_PictureFileDiskCleaner() = default;
    virtual ~M_PictureFileDiskCleaner() = default;

    MOCK_METHOD2(moveFile, void(const std::string& oldFilenameWithPath, const std::string& newFileNameWithPath));
};