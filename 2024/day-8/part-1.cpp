#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::ifstream ifs("sample-input.txt");
  std::string line;

  std::map<char, std::vector<std::pair<int, int> > > antennaFrequencies;
  std::set<std::pair<int, int> > antinodePositions;

  int lineNum = 0;
  while (std::getline(ifs, line)) {
    for (int i = 0; i < line.length(); i++) {
      if (antennaFrequencies.find(line[i]) == antennaFrequencies.end()) {
        std::vector<std::pair<int, int> > newValue;
        newValue.push_back(std::make_pair(i, lineNum));
        antennaFrequencies[line[i]] = newValue;
      } else {
        antennaFrequencies.at(line[i]).push_back(std::make_pair(i, lineNum));
      }
    }

    lineNum++;
  }

  auto it = antennaFrequencies.begin();
  for (int freq = 0; freq < antennaFrequencies.size(); freq++) {
    std::vector<std::pair<int, int> > positions = it->second;

    for (int antenna = 0; antenna < positions.size(); antenna++) {
      auto [x1, y1] = positions[antenna];
      for (int matchAntenna = antenna + 1; matchAntenna < positions.size();
           matchAntenna++) {
        auto [x2, y2] = positions[matchAntenna];

        int distX = x2 - x1;
        int distY = y2 - y1;

        antinodePositions.insert(std::make_pair(x1 - distX, y1 - distY));
        antinodePositions.insert(std::make_pair(x2 + distX, y2 + distY));
      }
    }
    std::advance(it, 1);
  }

  std::cout << antinodePositions.size() << std::endl;

  return 0;
}
