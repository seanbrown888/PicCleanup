
#include "gtest/gtest.h"

#include "../PicCleanupLib/PicCleanupBL.h"
#include "M_PictureFileDiskCleaner.h"
#include "M_RecursiveFileListingProvider.h"

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
        const std::string input_filepath = "this/package/testdata/myinputfile.dat";
        const std::string output_filepath = "this/package/testdata/myoutputfile.dat";
        
        
        // EXPECT_EQ(f.Bar(input_filepath, output_filepath), 0);
    }

    // Tests that Foo does Xyz.
    TEST_F(PicCleanupBLTest, DoesXyz) {
        // Exercises the Xyz feature of Foo.
    }

}  // namespace

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}