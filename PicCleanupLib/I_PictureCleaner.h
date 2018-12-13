#pragma once

#include <vector>
#include <string>

class I_PictureCleaner
{
public:
    I_PictureCleaner() = default;
    virtual ~I_PictureCleaner() = default;

    virtual void cleanup(const std::string& directoryPath, const std::vector<std::string>& pictureFileExtensionsToClean) = 0;
};