#include <iostream>
#include "ExprCalculator.h"

int main(int argc, char *argv[]) {
  std::string expr;
  std::cin >> expr;
  std::cout << ExprCalculator(expr).calculate();
  return 0;
}
