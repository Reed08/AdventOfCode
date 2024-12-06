#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>
#include <vector>

int main() {
    std::string line;
    std::unordered_set<std::string> uniquePositions;
    std::ifstream ifs("input.txt");
    std::vector<std::vector<char> > map;
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
                    case '^': playerDir = 1; break;
                    case '>': playerDir = 2; break;
                    case 'v': playerDir = 3; break;
                    case '<': playerDir = 4; break;
                }
                playerX = x;
                playerY = y;
                uniquePositions.insert(std::to_string(x) + "," + std::to_string(y));
            }
        }
    }

    while (playerY >= 0 && playerY < map.size() && playerX >= 0 && playerX < map[0].size()) {
        int targetX = playerX;
        int targetY = playerY;

        switch (playerDir) {
            case 1: targetY--; break;
            case 2: targetX++; break;
            case 3: targetY++; break;
            case 4: targetX--; break;
        }

        if (targetX >= 0 && targetX < map[0].size() &&
            targetY >= 0 && targetY < map.size() &&
            map[targetY][targetX] == '#') {
            playerDir = playerDir == 4 ? 1 : playerDir + 1;
        } else {
            playerX = targetX;
            playerY = targetY;
            if (playerX >= 0 && playerX < map[0].size() &&
                playerY >= 0 && playerY < map.size()) {
                uniquePositions.insert(std::to_string(playerX) + "," + std::to_string(playerY));
            }
        }
    }

    std::cout << uniquePositions.size() << std::endl;
    return 0;
}
