#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <string>
#include <vector>

#include "..\PicCleanupLib\DuplicateFileNameFileFinder.h"

namespace {

    class DuplicateFileNameFinderTest : public ::testing::Test {
    protected:
        DuplicateFileNameFinderTest() {
        }

        ~DuplicateFileNameFinderTest() override {
        }

        void SetUp() override {
        }

        void TearDown() override {

        }

       DuplicateFileNameFileFinder duplicateFinder;
    };

    // Finds a file with the same filename in a different directory
    TEST_F(DuplicateFileNameFinderTest, FindsDuplicateFile) {
        
    }

}  // namespace