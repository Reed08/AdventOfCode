#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ifstream input("input.txt");
    std::string line;

    int safeReports = 0;

    while (std::getline(input, line)) {
        bool isSafe = true;
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
            isSafe = false;
        }
        lastN = n;
        while (iss >> n) {
            if (!isSafe) break;
            if ((ascending && n < lastN) || (!ascending && n > lastN) || (std::abs(n - lastN) < 1) || (std::abs(n - lastN) > 3)) {
                isSafe = false;
                break;
            }
            lastN = n;
        }
        if (isSafe) {
            safeReports++;
        }
    }
    std::cout << safeReports << std::endl;
}
