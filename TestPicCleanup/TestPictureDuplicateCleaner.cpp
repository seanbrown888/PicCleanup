#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <string>
#include <vector>

#include "..\PicCleanupLib\PictureFileInfo.h"
#include "..\PicCleanupLib\PictureDuplicateCleaner.h"

#include "M_PictureFileDiskCleaner.h"
#include "M_DuplicateFileFinder.h"

using ::testing::_;
using ::testing::Return;

namespace {

    class PictureDuplicateCleanerTest : public ::testing::Test {
    protected:
        PictureDuplicateCleanerTest() : cleaner_(duplicateFileFinder_, diskCleaner_) {
        }

        ~PictureDuplicateCleanerTest() override {
        }

        void SetUp() override {
        }

        void TearDown() override {

        }

        M_DuplicateFileFinder duplicateFileFinder_;
        M_PictureFileDiskCleaner diskCleaner_;

        PictureDuplicateCleaner cleaner_;
    };

    // 
    TEST_F(PictureDuplicateCleanerTest, SomeSortOfClean) {
      
        // Setup test data
        std::string directoryToClean("c:\\pictures");

        PictureFileInfo oneFile("file1.png", directoryToClean);
        PictureFileInfo twoFile("file2.jpg", directoryToClean);
        PictureFileInfo duplicateOfOneFile("file1.png", directoryToClean + "\\otherDir");
        PictureFileInfo duplicateOfTwoFile("file2.jpg", directoryToClean + "\\otherDir");

        std::vector<PictureFileInfo> oneFileDuplicates = { duplicateOfOneFile };
        std::vector<PictureFileInfo> twoFileDuplicates = { duplicateOfTwoFile };
    
        std::unordered_map<PictureFileInfo, std::vector<PictureFileInfo>> testInputData = { {oneFile, oneFileDuplicates}, {twoFile, twoFileDuplicates} };

        // Ensure test data is used
        ON_CALL(duplicateFileFinder_, findDuplicateFiles(_, _)).WillByDefault(Return(testInputData));

        // Setup expected output
        EXPECT_CALL(diskCleaner_, moveFile(directoryToClean + "\\file1.png", directoryToClean + "\\originals\\file1.png"));
        EXPECT_CALL(diskCleaner_, moveFile(directoryToClean + "\\otherDir\\file1.png", directoryToClean + "\\duplicates\\otherDir-file1.png"));
        EXPECT_CALL(diskCleaner_, moveFile(directoryToClean + "\\file2.jpg", directoryToClean + "\\originals\\file2.jpg"));
        EXPECT_CALL(diskCleaner_, moveFile(directoryToClean + "\\otherDir\\file2.jpg", directoryToClean + "\\duplicates\\otherDir-file2.jpg"));

        // Perform action to get the expected output
        cleaner_.cleanup(directoryToClean, { ".png", ".jpg" });
    }

}  // namespace