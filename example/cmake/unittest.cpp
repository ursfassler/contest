#include "gmock/gmock.h"
#include <ide_printer.h>
#include <iostream>

TEST(UnitTest, Failing_Test) { EXPECT_FALSE(true); }

TEST(UnitTest, Succeeding_Test) { EXPECT_TRUE(true); }

TEST(UnitTest, Succeeding_Test_2) { EXPECT_FALSE(false); }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  ::testing::TestEventListeners &listeners =
      ::testing::UnitTest::GetInstance()->listeners();

  delete listeners.Release(listeners.default_result_printer());
  listeners.Append(new IdePrinter());

  return RUN_ALL_TESTS();
}
