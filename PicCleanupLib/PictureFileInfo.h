#pragma once

#include <string>
#include <unordered_map>

struct PictureFileInfo
{
    PictureFileInfo(std::string nameOfFile, std::string pathOfParent)
    : filename(nameOfFile), parentPath(pathOfParent) {}

    bool operator==(const PictureFileInfo& rhs) const { return filename == rhs.filename && parentPath == rhs.parentPath;}
    bool operator!=(const PictureFileInfo& rhs) const { return !(operator==(rhs)); }

    std::string filename;
    std::string parentPath;
};

namespace std {
    template <> struct hash<PictureFileInfo>
    {
        std::size_t operator()(const PictureFileInfo& k) const
        {
            return (std::hash<std::string>()(k.filename)
                ^ (std::hash<std::string>()(k.parentPath) << 1));
        }
    };
}