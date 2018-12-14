#include "stdafx.h"
#include "PictureDuplicateCleaner.h"
#include "PictureFileInfo.h"

PictureDuplicateCleaner::PictureDuplicateCleaner(I_DuplicateFileFinder& fileDuplicateFinder, I_FileOnDiskMover& diskMover)
: fileDuplicateFinder_(fileDuplicateFinder), diskMover_(diskMover)
{
}


PictureDuplicateCleaner::~PictureDuplicateCleaner()
{
}

void PictureDuplicateCleaner::cleanup(const std::string& directoryPath, const std::vector<std::string>& pictureFileExtensionsToClean)
{
    // Get duplicates
    std::unordered_map<PictureFileInfo, std::vector<PictureFileInfo>> duplicates = fileDuplicateFinder_.findDuplicateFiles(directoryPath, pictureFileExtensionsToClean);

    // Move original (key) to original folder and duplicates to duplicate folder with original folder appended to folder name
    std::string pathForOriginals(directoryPath + "\\originals\\");
    std::string pathForDuplicates(directoryPath + "\\duplicates");

    for (const auto& kv : duplicates)
    {
        // Move original
        std::string pathForOrignalToGo = pathForOriginals + kv.first.filename;
        diskMover_.moveFile(kv.first.parentPath + '\\' + kv.first.filename, pathForOrignalToGo);

        std::string moveOne = kv.first.parentPath + '\\' + kv.first.filename;
        std::string moveTwo = pathForOrignalToGo;

        // Move and rename all duplicates
        for(const auto& pic : kv.second)
        {
            int positionOfOriginalDir = pic.parentPath.find_last_of('\\');
            std::string duplicateOriginalDir = pic.parentPath.substr(positionOfOriginalDir);
            std::string newFileNameWithPathForDuplicate = pathForDuplicates + duplicateOriginalDir + '-' + pic.filename;
            std::string moveThree = pic.parentPath + '\\' + pic.filename;

            diskMover_.moveFile(pic.parentPath + '\\' + pic.filename, newFileNameWithPathForDuplicate);
        }

    }

}
