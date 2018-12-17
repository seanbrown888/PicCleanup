#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "gmock/gmock-matchers.h"

#include <string>
#include <vector>

#include "../PicCleanupLib/PictureFileInfo.h"
#include "../PicCleanupLib/RecursiveFileListingProvider.h"

namespace {

    class FileListingProviderTest : public ::testing::Test {
    protected:
        FileListingProviderTest()  {
        }

        ~FileListingProviderTest() override {
        }

        void SetUp() override {
        }

        void TearDown() override {
        }

        RecursiveFileListingProvider fileListingProvider_;
    };

    // Returns list of files with a given extension, starting with starting directory
    //  and recursively within it
    TEST_F(FileListingProviderTest, ProvidesRequestedFiletypesRecusively) {
        std::string directoryToStartSearch("..\\testSandbox\\");
        std::vector<std::string> fileTypesToSearchFor = {".jpg", ".png"};
        std::vector<PictureFileInfo> expected = {PictureFileInfo("thumbup.jpg", "..\\testSandbox"), 
                                                 PictureFileInfo("thumbup.png", "..\\testSandbox"),
                                                 PictureFileInfo("thumbDown.jpg", "..\\testSandbox\\recursive"),
                                                 PictureFileInfo("thumbDown.jpg", "..\\testSandbox\\second"),
                                                 PictureFileInfo("thumbDown.jpg", "..\\testSandbox\\recursive\\second") };

        std::vector<PictureFileInfo> actual = fileListingProvider_.filesInDirectory(directoryToStartSearch, fileTypesToSearchFor);

        EXPECT_THAT(actual, ::testing::UnorderedElementsAreArray(expected));
    }

}  // namespace