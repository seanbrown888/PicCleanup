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
        FileOnDiskMoverTest() : fileToMove_("..\\testSandbox\\Nope.txt") {
        }

        ~FileOnDiskMoverTest() override {
        }

        void SetUp() override {
        }

        void TearDown() override {
        
        }

        void putFileBackForNextTestCase(const std::string& oldLocation, const std::string& newLocation)
        {
            if (fs::exists(oldLocation))
            {
                std::error_code errorCode;
                fs::rename(oldLocation, newLocation, errorCode);
            }
        }

        FileOnDiskMover fileOnDiskMover_;
        std::string fileToMove_;
    };

    // Moves a file on disk from one location to another
    TEST_F(FileOnDiskMoverTest, MovesFileSameDir) {
        std::string newFileLocation("..\\testSandbox\\Nope-Moved.txt");

        fileOnDiskMover_.moveFile(fileToMove_, newFileLocation);

        EXPECT_TRUE(fs::exists(newFileLocation));

        putFileBackForNextTestCase(newFileLocation, fileToMove_);
    }

    // Moves a file on disk from one location to another, where the new directory doesn't exist
    TEST_F(FileOnDiskMoverTest, MovesFileNonExistantDir) {
        std::string nonexistantDir("..\\testSandbox\\Duplicates");
        std::string newFileLocation(nonexistantDir + "\\Nope-Moved.txt");

        fileOnDiskMover_.moveFile(fileToMove_, newFileLocation);

        EXPECT_TRUE(fs::exists(newFileLocation));

        putFileBackForNextTestCase(newFileLocation, fileToMove_);
        fs::remove_all(nonexistantDir);
    }

}  // namespace