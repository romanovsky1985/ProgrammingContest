#include <iostream>

#include "RomanFraction.h"

int main(int argc, char *argv[]) {
  std::string romanString;
  std::cin >> romanString;
  std::cout << RomanFraction(romanString);

  return 0;
}

