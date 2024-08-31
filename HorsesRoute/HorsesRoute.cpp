#include "HorsesRoute.h"

int HorsesRoute::getX(const std::string& cell) {
  return cell[0] - 'A';
}

int HorsesRoute::getY(const std::string& cell) {
  return cell[1] - '1';
}

std::string HorsesRoute::getCell(int x, int y) {
  std::string cell;
  cell += 'A' + x;
  cell += '1' + y;
  return cell;
}

std::string HorsesRoute::getRoute(const std::string& finish) {
  int x = getX(finish);
  int y = getY(finish);
  return routes[x][y];
}

/*
 * Сначала записываем маршрут из стартового поля в поля, до которых
 * из него можно попасть за один ход. Далеее уже из этих полей записываем
 * маршруты в поля, до которых можно попасть из них, и так далее до тех
 * пор, пока не заполним все поля. В нужном поле будет нужный маршрут.
 * То есть, сперва обрабатываются те поля, в которые дойдем за первый ход,
 * далее те, в которые доходим еще за один ход, для чего удобно использовать
 * очередь. Для того, чтобы соблюдался лексикографический приоритет важен
 * правильный порядок выбора полей и в рамках одного шага - движение по x
 * от меньшего к большему приоритетнее такого движения по y (массив moves)
*/
HorsesRoute::HorsesRoute(const std::string& start) {
  int x = getX(start);
  int y = getY(start);
  routes[x][y] = getCell(x, y);
  std::queue<int> cells;
  cells.push(x);
  cells.push(y);
  int moves[8][2] = {{-2, -1}, {-2, +1}, {-1, -2},
      {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
  while (!cells.empty()) {
    int x1 = cells.front();
    cells.pop();
    int y1 = cells.front();
    cells.pop();
    for (auto move : moves) {
      int x2 = x1 + move[0];
      int y2 = y1 + move[1];
      if (x2 >= 0 && x2 < 8 && y2 >=0 && y2 < 8 && routes[x2][y2].empty()) {
        routes[x2][y2] = routes[x1][y1] + ' ' + getCell(x2, y2);
        cells.push(x2);
        cells.push(y2);
      }
    }
  }
}
