#ifndef IDE_PRINTER_H
#define IDE_PRINTER_H

#include "gtest/gtest.h"
#include <iostream>

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


#endif // IDE_PRINTER_H
