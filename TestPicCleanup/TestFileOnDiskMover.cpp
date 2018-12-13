#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <filesystem>
#include <string>
#include <vector>

#include "..\PicCleanupLib\FileOnDiskMover.h"

namespace fs = std::experimental::filesystem;

namespace {

    class FileOnDiskMoverTest : public ::testing::Test {
    protected:
        FileOnDiskMoverTest() : fileToMove_("..\\testSandbox\\Nope.txt"), newFileLocation_("..\\testSandbox\\Nope-Moved.txt") {
        }

        ~FileOnDiskMoverTest() override {
        }

        void SetUp() override {
        }

        void TearDown() override {
            // Put the file back for next test
            if (fs::exists(newFileLocation_))
            {
                fs::rename(newFileLocation_, fileToMove_);
            }
        }

        FileOnDiskMover fileOnDiskMover_;

        std::string fileToMove_;
        std::string newFileLocation_;

    };

    // Moves a file on disk from one location to another
    TEST_F(FileOnDiskMoverTest, MovesFileSameDir) {

        fileOnDiskMover_.moveFile(fileToMove_, newFileLocation_);

        EXPECT_TRUE(fs::exists(newFileLocation_));
    }

}  // namespace