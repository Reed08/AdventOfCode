#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ifstream input("input.txt");
    std::string line;

    int safeReports = 0;

    while (std::getline(input, line)) {
        int numBadLevels = 0;
        bool ascending;
        std::istringstream iss(line);
        int lastN, n;
        iss >> n;
        lastN = n;
        iss >> n;
        if (n > lastN) {
            ascending = true;
        } else {
            ascending = false;
        }
        if ((std::abs(n - lastN) < 1) || (std::abs(n - lastN) > 3)) {
            numBadLevels++;
            std::cout << "UNSAFE - last: " << lastN << ", current: " << n << std::endl;
        } else {
            std::cout << "SAFE - last: " << lastN << ", current: " << n << std::endl;
            lastN = n;
        }
        int iter = 0;
        while (iss >> n) {
            if (numBadLevels > 1) break;
            if (iter == 0 && numBadLevels == 1) {
                if (n > lastN) {
                    ascending = true;
                } else {
                    ascending = false;
                }
            }
            if ((ascending && n < lastN) || (!ascending && n > lastN) || (std::abs(n - lastN) < 1) || (std::abs(n - lastN) > 3)) {
                numBadLevels++;
                std::cout << "UNSAFE - last: " << lastN << ", current: " << n << std::endl;
            } else {
                std::cout << "SAFE - last: " << lastN << ", current: " << n << std::endl;
                lastN = n;
            }
            iter++;
        }
        if (numBadLevels <= 1) {
            safeReports++;
            std::cout << "SAFE!!" << std::endl;
        } else {
            std::cout << "UNSAFE!!" << std::endl;
        }
    }
    std::cout << safeReports << std::endl;
}
