#include "gmock/gmock.h"
#include <ide_printer.h>

TEST(UnitTest, test1) { EXPECT_FALSE(true); }

TEST(UnitTest, test2) { EXPECT_TRUE(true); }

TEST(UnitTest, test3) { EXPECT_TRUE(false); }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  ::testing::TestEventListeners &listeners =
      ::testing::UnitTest::GetInstance()->listeners();

  delete listeners.Release(listeners.default_result_printer());
  listeners.Append(new IdePrinter());

  return RUN_ALL_TESTS();
}
