#include <iostream>
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class IdePrinter :
    public ::testing::EmptyTestEventListener
{

    void OnTestPartResult(const ::testing::TestPartResult& result) override
    {
      if (result.failed()) {
        std::istringstream f(result.message());

        std::string line;
        bool first = true;
        while (getline(f, line, '\n'))
        {
          std::cerr << result.file_name() << ":" << result.line_number() << ":0: ";
          if (first) {
            std::cerr << "error: ";
          }
          std::cerr << line << std::endl;

          first = false;
        }
      }
    }

};

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




int main(int argc, char** argv)
{
  testing::InitGoogleMock(&argc, argv);

  ::testing::TestEventListeners& listeners =
      ::testing::UnitTest::GetInstance()->listeners();

  delete listeners.Release(listeners.default_result_printer());
  listeners.Append(new IdePrinter());

  return RUN_ALL_TESTS();
}
