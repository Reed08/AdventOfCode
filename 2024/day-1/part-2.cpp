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

    int similarityScore = 0;

    for (int i = 0; i < list1.size(); i++) {
        int numOccurences = 0;
        for (int j = 0; j < list2.size(); j++) {
            if (list2[j] == list1[i]) {
                numOccurences++;
            }
        }

        similarityScore += list1[i] * numOccurences;
    }

    std::cout << similarityScore << std::endl;
}
