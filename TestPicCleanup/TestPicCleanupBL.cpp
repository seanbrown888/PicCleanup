
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
        std::string directoryToClean("..\\testSandbox\\acceptance");
        PictureFileInfo oneFile("thumbup.png", directoryToClean);
        PictureFileInfo twoFile("thumbup.jpg", directoryToClean);
        PictureFileInfo duplicateOfOneFile("thumbup.png", directoryToClean + "\\otherDir");
        std::vector<PictureFileInfo> testInputData = {oneFile, twoFile, duplicateOfOneFile};

        // Ensure test data is used
        ON_CALL(fileListingProvider_, filesInDirectory(_, _)).WillByDefault(Return(testInputData));

        // Setup expected output
        EXPECT_CALL(diskCleaner_, moveFile(directoryToClean + "\\thumbup.png", directoryToClean + "\\originals\\thumbup.png"));
        EXPECT_CALL(diskCleaner_, moveFile(directoryToClean + "\\thumbup.jpg", directoryToClean + "\\originals\\thumbup.jpg"));
        EXPECT_CALL(diskCleaner_, moveFile(directoryToClean + "\\otherDir\\thumbup.png", directoryToClean + "\\duplicates\\thumbup-otherDir.png"));

        // Perform action to get the expected output
        bl_.cleaner().cleanup(directoryToClean, {".png", ".jpg"} );
    }

}  // namespace

int main(int argc, char **argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}