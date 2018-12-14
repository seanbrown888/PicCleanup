#include "stdafx.h"
#include "DuplicateFileNameFileFinder.h"


DuplicateFileNameFileFinder::DuplicateFileNameFileFinder(I_RecursiveFileListingProvider& fileListingProvider)
: fileListingProvider_(fileListingProvider)
{
}


DuplicateFileNameFileFinder::~DuplicateFileNameFileFinder()
{
}

std::unordered_map<PictureFileInfo, std::vector<PictureFileInfo>> DuplicateFileNameFileFinder::findDuplicateFiles(const std::string & directoryPath, const std::vector<std::string>& fileExtensions)
{
    std::unordered_map<PictureFileInfo, std::vector<PictureFileInfo>> duplicates;
    std::unordered_map<std::string, std::unordered_map<PictureFileInfo, std::vector<PictureFileInfo>>::iterator> duplicatesLocatorHelper;

    std::vector<PictureFileInfo> allFilesToCheckForDuplicates = fileListingProvider_.filesInDirectory(directoryPath, fileExtensions);

    for (const auto& file : allFilesToCheckForDuplicates)
    {
        std::vector<PictureFileInfo> fileDuplicates;
        auto duplicateFindResult = duplicatesLocatorHelper.find(file.filename);

        if (duplicateFindResult != duplicatesLocatorHelper.end()) // file already in map
        {
            duplicateFindResult->second->second.push_back(file);
        }
        else
        {
            auto insertionResult = duplicates.emplace(file, fileDuplicates);
            duplicatesLocatorHelper.emplace(file.filename, insertionResult.first);
        }
    }

    return duplicates;
}
