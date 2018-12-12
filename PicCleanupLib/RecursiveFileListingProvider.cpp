#include "stdafx.h"
#include "RecursiveFileListingProvider.h"

#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::experimental::filesystem;

RecursiveFileListingProvider::RecursiveFileListingProvider()
{
}


RecursiveFileListingProvider::~RecursiveFileListingProvider()
{
}

std::vector<PictureFileInfo> RecursiveFileListingProvider::filesInDirectory(const std::string & directoryPath, const std::vector<std::string>& fileExtensionsToInclude)
{
    std::vector<PictureFileInfo> matchingFiles;

    fs::recursive_directory_iterator directoryIt(directoryPath);
    fs::recursive_directory_iterator directoryEnd;

    while (directoryIt != directoryEnd)
    {
        if (fs::is_directory(directoryIt->path()))
        {
            directoryIt.disable_recursion_pending();
        }
        else if (std::find(fileExtensionsToInclude.begin(), fileExtensionsToInclude.end(), directoryIt->path().extension()) != fileExtensionsToInclude.end())
        {
            matchingFiles.push_back(PictureFileInfo(directoryIt->path().filename().string(), directoryIt->path().parent_path().string()));
        }

        std::error_code errorCode;
        directoryIt.increment(errorCode);
    }
    
    return matchingFiles;
}
