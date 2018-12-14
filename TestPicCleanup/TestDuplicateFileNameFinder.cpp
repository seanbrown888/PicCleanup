#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <string>
#include <vector>

#include "..\PicCleanupLib\DuplicateFileNameFileFinder.h"
#include "..\PicCleanupLib\PictureFileInfo.h"
#include "M_RecursiveFileListingProvider.h"

using ::testing::_;
using ::testing::Return;

namespace {

    class DuplicateFileNameFinderTest : public ::testing::Test {
    protected:
        DuplicateFileNameFinderTest() : duplicateFinder_(fileListingProvider_) {
        }

        ~DuplicateFileNameFinderTest() override {
        }

        void SetUp() override {
        }

        void TearDown() override {

        }

        M_RecursiveFileListingProvider fileListingProvider_;
        DuplicateFileNameFileFinder duplicateFinder_;
    };

    // Finds a file with the same filename in a different directory
    TEST_F(DuplicateFileNameFinderTest, FindsDuplicateFile) {
        std::string directoryToClean("c:\\pictures");
        PictureFileInfo oneFile("file1.png", directoryToClean);
        PictureFileInfo twoFile("file2.jpg", directoryToClean);
        PictureFileInfo duplicateOfOneFile("file1.png", directoryToClean + "\\otherDir");
        PictureFileInfo duplicateOfTwoFile("file2.jpg", directoryToClean + "\\otherDir");
        std::vector<PictureFileInfo> testInputData = { oneFile, twoFile, duplicateOfOneFile, duplicateOfTwoFile };

        // Ensure test data is used
        ON_CALL(fileListingProvider_, filesInDirectory(_, _)).WillByDefault(Return(testInputData));

        std::unordered_map<PictureFileInfo, std::vector<PictureFileInfo>> expectedData = { {oneFile, {duplicateOfOneFile}}, {twoFile, {duplicateOfTwoFile}} };
        std::unordered_map<PictureFileInfo, std::vector<PictureFileInfo>> actualData = duplicateFinder_.findDuplicateFiles(directoryToClean, {".jpg", ".png"} );

        // assert it's in there, then compare the "values" ie compare the vector containers
        for (const auto& kv : expectedData)
        {
            auto actualDuplicateListingIt = actualData.find(kv.first);
            EXPECT_TRUE(actualDuplicateListingIt != actualData.end());
            EXPECT_THAT(actualDuplicateListingIt->second, ::testing::UnorderedElementsAreArray(kv.second));
        }
    }

}  // namespace