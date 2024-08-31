#include <iostream>

#include "HorsesRoute.h"

int main(int argc, char *argv[]) {
  std::string start, finish;
  std::cin >> start >> finish;
  std::cout << HorsesRoute(start).getRoute(finish);
  return 0;
}
