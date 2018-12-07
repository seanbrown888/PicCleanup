
#include <vector>
#include "gtest/gtest.h"

#include "../PicCleanupLib/PictureFileInfo.h"
#include "../PicCleanupLib/PicCleanupBL.h"

#include "M_PictureFileDiskCleaner.h"
#include "M_RecursiveFileListingProvider.h"

using ::testing::_;
using ::testing::Return;

namespace {

    class PicCleanupBLTest : public ::testing::Test {
    protected:
        

        PicCleanupBLTest() : bl_(fileListingProvider_, diskCleaner_) {   
        }

        ~PicCleanupBLTest() override {
        }

        void SetUp() override {
        }

        void TearDown() override {
        }

        M_RecursiveFileListingProvider fileListingProvider_;
        M_PictureFileDiskCleaner diskCleaner_;

        PicCleanupBL bl_;
    };

    // Given a list of picture files with duplicates
    // When prompted
    // Then the duplicates will be moved to the duplicate folder and original to original folder
    TEST_F(PicCleanupBLTest, DoesSomething) {
      
        // Setup test data
        PictureFileInfo oneFile("file1.png", "c:\\pictures\\imported");
        PictureFileInfo twoFile("file2.png", "c:\\pictures\\imported");
        PictureFileInfo duplicateOfOneFile("file1.png", "c:\\pictures\\otherImportedDirectory");
        std::vector<PictureFileInfo> testInputData = {oneFile, twoFile, duplicateOfOneFile};

        // Ensure test data is used
        ON_CALL(fileListingProvider_, filesInDirectory(_, _)).WillByDefault(Return(testInputData));

        // Setup expected output
        EXPECT_CALL(diskCleaner_, moveFile("c:\\pictures\\imported\\file1.png", "c:\\pictures\\originals\\file1.png"));
        EXPECT_CALL(diskCleaner_, moveFile("c:\\pictures\\imported\\file2.png", "c:\\pictures\\originals\\file2.png"));
        EXPECT_CALL(diskCleaner_, moveFile("c:\\pictures\\otherImportedDirectory\\file1.png", "c:\\pictures\\duplicates\\file1-otherImportedDirectory.png"));

        // Perform action to get the expected output
        // ACTION - not actually sure what action to call yet, good place to start ;)
        //        - Another good place that could be started in parallel (if there was more than one of me, concretes of our Mocks from above
    }

}  // namespace

int main(int argc, char **argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}