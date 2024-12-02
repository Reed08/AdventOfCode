#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::vector<int> list1;
    std::vector<int> list2;
    std::string line;

    while (std::getline(std::cin, line) && !line.empty()) {
        int n1, n2;
        std::istringstream iss(line);
        if (iss >> n1 >> n2) {
            list1.push_back(n1);
            list2.push_back(n2);
        }
    }

    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    int total = 0;

    for (int i = 0; i < list1.size(); i++) {
        int diff = std::abs(list2[i] - list1[i]);
        total += diff;
    }

    std::cout << total << std::endl;

    return 0;
}
