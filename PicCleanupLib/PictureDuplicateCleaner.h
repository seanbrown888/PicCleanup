#pragma once

#include <string>
#include <vector>

#include "I_PictureCleaner.h"

class PictureDuplicateCleaner : public I_PictureCleaner
{
public:
    PictureDuplicateCleaner();
    ~PictureDuplicateCleaner();

    void cleanup(const std::string& directoryPath, const std::vector<std::string>& pictureFileExtensionsToClean);
};

