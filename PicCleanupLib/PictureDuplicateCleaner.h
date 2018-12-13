#pragma once

#include <string>
#include <vector>

#include "I_PictureCleaner.h"

#include "I_DuplicateFileFinder.h"
#include "I_FileOnDiskMover.h"

class PictureDuplicateCleaner : public I_PictureCleaner
{
public:
    PictureDuplicateCleaner(I_DuplicateFileFinder& fileDuplicateFinder, I_FileOnDiskMover& diskMover);
    ~PictureDuplicateCleaner();

    void cleanup(const std::string& directoryPath, const std::vector<std::string>& pictureFileExtensionsToClean);

private:
    I_DuplicateFileFinder& fileDuplicateFinder_;
    I_FileOnDiskMover& diskMover_;
};

