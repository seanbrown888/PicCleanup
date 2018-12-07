
#include <vector>

#include "gtest/gtest.h"

#include "../PicCleanupLib/PictureFileInfo.h"
#include "../PicCleanupLib/PicCleanupBL.h"
#include "M_PictureFileDiskCleaner.h"
#include "M_RecursiveFileListingProvider.h"

using ::testing::_;
using ::testing::Return;

namespace {

    // The fixture for testing class Foo.
    class PicCleanupBLTest : public ::testing::Test {
    protected:
        

        PicCleanupBLTest() : bl_(fileListingProvider_, diskCleaner_) {
            // You can do set-up work for each test here.
            
        }

        ~PicCleanupBLTest() override {
            // You can do clean-up work that doesn't throw exceptions here.
        }

        // If the constructor and destructor are not enough for setting up
        // and cleaning up each test, you can define the following methods:

        void SetUp() override {
            // Code here will be called immediately after the constructor (right
            // before each test).
        }

        void TearDown() override {
            // Code here will be called immediately after each test (right
            // before the destructor).
        }

        // Objects declared here can be used by all tests in the test case for Foo.
        M_RecursiveFileListingProvider fileListingProvider_;
        M_PictureFileDiskCleaner diskCleaner_;

        PicCleanupBL bl_;
    };

    // Given a list of picture files with duplicates
    // When prompted
    // Then the duplicates will be moved to the duplicate folder and original to original folder
    TEST_F(PicCleanupBLTest, DoesSomething) {
      
        PictureFileInfo oneFile("file1.png", "c:\\pictures\\imported");
        PictureFileInfo twoFile("file2.png", "c:\\pictures\\imported");
        PictureFileInfo duplicateOfOneFile("file1.png", "c:\\pictures\\otherImportedDirectory");

        std::vector<PictureFileInfo> testInputData = {oneFile, twoFile, duplicateOfOneFile};

        ON_CALL(fileListingProvider_, filesInDirectory(_, _)).WillByDefault(Return(testInputData));

        EXPECT_CALL(diskCleaner_, moveFile("c:\\pictures\\imported\\file1.png", "c:\\pictures\\originals\\file1.png"));
        EXPECT_CALL(diskCleaner_, moveFile("c:\\pictures\\imported\\file2.png", "c:\\pictures\\originals\\file2.png"));
        EXPECT_CALL(diskCleaner_, moveFile("c:\\pictures\\otherImportedDirectory\\file1.png", "c:\\pictures\\duplicates\\file1-otherImportedDirectory.png"));

    }

    // Tests that Foo does Xyz.
    TEST_F(PicCleanupBLTest, DoesXyz) {
        // Exercises the Xyz feature of Foo.
    }

}  // namespace

int main(int argc, char **argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}