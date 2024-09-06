#include <iostream>

#include "RomanFraction.h"

int main(int argc, char *argv[]) {
  //RomanFraction rf("XX/XL");
  //int x;
  //std::cin >> x;
  //std::cout << RomanFraction::toRoman(x) << std::endl;
  //std::string roman;
  //std::cin >> roman;
  //std::cout << RomanFraction::toInt(roman) << std::endl;
  std::string romanString;
  std::cin >> romanString;
  std::cout << RomanFraction(romanString);

  return 0;
}

