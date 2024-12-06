#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <vector>

int main() {
  std::string line;
  int total = 0;
  std::ifstream ifs("sample-input.txt");
  std::vector<std::vector<char>> map;
  while (std::getline(ifs, line)) {
    std::vector<char> newLine;
    for (int i = 0; i < line.length(); i++) {
      newLine.push_back(line[i]);
    }
    map.push_back(newLine);
  }

  int playerX, playerY, playerDir;
  for (int y = 0; y < map.size(); y++) {
    for (int x = 0; x < map[y].size(); x++) {
      if (map[y][x] != '.' && map[y][x] != '#') {
        switch (map[y][x]) {
        case '^':
          playerDir = 1;
          break;
        case '>':
          playerDir = 2;
          break;
        case 'v':
          playerDir = 3;
          break;
        case '<':
          playerDir = 4;
          break;
        }
        playerX = x;
        playerY = y;
      }
    }
  }

  map[playerY][playerX] = '.';

  int initX = playerX;
  int initY = playerY;
  int initDir = playerDir;

  for (int obstacleY = 0; obstacleY < map.size(); obstacleY++) {
    for (int obstacleX = 0; obstacleX < map[obstacleY].size(); obstacleX++) {
      if (map[obstacleY][obstacleX] != '.')
        continue;
      map[obstacleY][obstacleX] = '#';

      std::set<std::tuple<int, int, int>> visited;

      while (playerY >= 0 && playerY < map.size() && playerX >= 0 &&
             playerX < map[0].size()) {

        if (visited.count({playerX, playerY, playerDir}) > 0) {
          total++;
          break;
        }
        visited.insert({playerX, playerY, playerDir});
        int targetX = playerX;
        int targetY = playerY;

        switch (playerDir) {
        case 1:
          targetY--;
          break;
        case 2:
          targetX++;
          break;
        case 3:
          targetY++;
          break;
        case 4:
          targetX--;
          break;
        }

        if (targetX >= 0 && targetX < map[0].size() && targetY >= 0 &&
            targetY < map.size() && map[targetY][targetX] == '#') {
          // if (targetX == obstacleX && targetY == obstacleY) {
          //   if (hitDir == 0) {
          //     hitX = playerX;
          //     hitY = playerY;
          //     hitDir = playerDir;
          //   } else if (hitX == playerX && hitY == playerY &&
          //              hitDir == playerDir) {
          //     total++;
          //     break;
          //   }
          // }
          playerDir = playerDir == 4 ? 1 : playerDir + 1;
        } else {
          playerX = targetX;
          playerY = targetY;
        }
      }
      map[obstacleY][obstacleX] = '.';
      playerX = initX;
      playerY = initY;
      playerDir = initDir;
    }
  }

  std::cout << total << std::endl;
  return 0;
}
