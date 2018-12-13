#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <string>
#include <vector>

#include "..\PicCleanupLib\PictureDuplicateCleaner.h"

#include "M_PictureFileDiskCleaner.h"
#include "M_RecursiveFileListingProvider.h"

using ::testing::_;
using ::testing::Return;

namespace {

    class PictureDuplicateCleanerTest : public ::testing::Test {
    protected:
        PictureDuplicateCleanerTest() : cleaner_(fileListingProvider_, diskCleaner_) {
        }

        ~PictureDuplicateCleanerTest() override {
        }

        void SetUp() override {
        }

        void TearDown() override {

        }

        M_RecursiveFileListingProvider fileListingProvider_;
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
        std::vector<PictureFileInfo> testInputData = { oneFile, twoFile, duplicateOfOneFile };

        // Ensure test data is used
        ON_CALL(fileListingProvider_, filesInDirectory(_, _)).WillByDefault(Return(testInputData));

        // Setup expected output
        EXPECT_CALL(diskCleaner_, moveFile(directoryToClean + "\\file1.png", directoryToClean + "\\originals\\file1.png"));
        EXPECT_CALL(diskCleaner_, moveFile(directoryToClean + "\\file2.jpg", directoryToClean + "\\originals\\file2.jpg"));
        EXPECT_CALL(diskCleaner_, moveFile(directoryToClean + "\\otherDir\\file1.png", directoryToClean + "\\duplicates\\file1-otherDir.png"));

        // Perform action to get the expected output
        cleaner_.cleanup(directoryToClean, { ".png", ".jpg" });
    }

}  // namespace