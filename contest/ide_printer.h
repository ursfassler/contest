#ifndef IDE_PRINTER_H
#define IDE_PRINTER_H

#include "gtest/gtest.h"
#include <iostream>

class IdePrinter : public ::testing::EmptyTestEventListener {

  void OnTestPartResult(const ::testing::TestPartResult &result) override {
    if (result.failed()) {
      std::istringstream f(result.message());

      std::string line;
      bool first = true;
      while (getline(f, line, '\n')) {
        std::cout << result.file_name() << "(" << result.line_number()
                  << ":0): ";
        if (first) {
          std::cout << "error T0000: ";
        }
        std::cout << line << std::endl;

        first = false;
      }
    }
  }
};

#endif // IDE_PRINTER_H
