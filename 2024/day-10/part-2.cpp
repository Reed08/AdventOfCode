#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

std::map<std::pair<int, int>, std::vector<std::pair<int, int> > > reachableEnds;

void checkSurrounding(std::pair<int, int> startPos,
                      std::vector<std::string> map,
                      std::pair<int, int> original);

void checkFind(std::pair<int, int> thisCoord, std::vector<std::string> map,
               std::pair<int, int> original, int target) {
  if (target == 9) {
    reachableEnds[original].push_back(thisCoord);
  } else {
    checkSurrounding(thisCoord, map, original);
  }
}

void checkSurrounding(std::pair<int, int> startPos,
                      std::vector<std::string> map,
                      std::pair<int, int> original) {
  int x = startPos.first;
  int y = startPos.second;

  int target = map[y][x] - '0' + 1;

  if (y > 0 && map[y - 1][x] - '0' == target) {
    std::pair<int, int> thisCoord = std::make_pair(x, y - 1);

    checkFind(thisCoord, map, original, target);
  }

  if (x < map[y].length() - 1 && map[y][x + 1] - '0' == target) {
    std::pair<int, int> thisCoord = std::make_pair(x + 1, y);

    checkFind(thisCoord, map, original, target);
  }

  if (y < map.size() - 1 && map[y + 1][x] - '0' == target) {
    std::pair<int, int> thisCoord = std::make_pair(x, y + 1);

    checkFind(thisCoord, map, original, target);
  }

  if (x > 0 && map[y][x - 1] - '0' == target) {
    std::pair<int, int> thisCoord = std::make_pair(x - 1, y);

    checkFind(thisCoord, map, original, target);
  }
}

int main() {
  std::ifstream ifs("input.txt");
  std::string line;
  std::vector<std::string> map;

  while (std::getline(ifs, line)) {
    map.push_back(line);
  }

  // loop over every 0
  for (int y = 0; y < map.size(); y++) {
    for (int x = 0; x < map[y].length(); x++) {
      if (map[y][x] == '0') {
        checkSurrounding(std::make_pair(x, y), map, std::make_pair(x, y));
      }
    }
  }

  int total = 0;

  for (const auto &entry : reachableEnds) {
    std::cout << entry.first.first << ", " << entry.first.second << std::endl;
    total += entry.second.size();
  }

  std::cout << total << std::endl;

  return 0;
}