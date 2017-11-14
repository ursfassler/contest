#include "gtest/gtest.h"


TEST(UnitTest, test1)
{
  EXPECT_FALSE(true);
}

TEST(UnitTest, test2)
{
  EXPECT_TRUE(true);
}

TEST(UnitTest, test3)
{
  EXPECT_TRUE(false);
}

