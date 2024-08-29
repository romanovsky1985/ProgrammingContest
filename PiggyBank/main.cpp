#include <iostream>
#include "PiggyBank.h"

int main(int argc, char *argv[]) {
  int totalWeight;
  std::cin >> totalWeight;
  PiggyBank piggyBank;
  piggyBank.readCoins(std::cin);
  std::cout << piggyBank.minValue(totalWeight);
  return 0;
}
