#ifndef _HORSESROUTE_H_
#define _HORSESROUTE_H_

#include <string>
#include <queue>

class HorsesRoute {

public:

  HorsesRoute(const std::string& start);

  std::string getRoute(const std::string& finish);

  static std::string getCell(int x, int y);

  static int getX(const std::string& cell);

  static int getY(const std::string& cell);

private:

  std::string routes[8][8];

};

#endif
