#include <cctype>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

int main() {
    std::ifstream ifs("input.txt");
    std::string line;
    std::vector< std::vector<char> > mat;
    int total = 0;

    // insert into 2d vector
    while (std::getline(ifs, line)) {
        std::istringstream iss(line);
        char c;
        std::vector<char> row;
        while (iss >> c) {
            row.push_back(c);
        }
        mat.push_back(row);
    }

    // check for a's
    // check horizontal forward matches
    for (int i = 1; i < mat.size() - 1; i++) {
        for (int j = 1; j < mat[i].size() - 1; j++) {
            if (std::tolower(mat[i][j]) == 'a') {
                if (((std::tolower(mat[i - 1][j - 1]) == 'm' && std::tolower(mat[i + 1][j + 1]) == 's') || (std::tolower(mat[i - 1][j - 1]) == 's' && std::tolower(mat[i + 1][j + 1]) == 'm')) && ((std::tolower(mat[i - 1][j + 1]) == 'm' && std::tolower(mat[i + 1][j - 1]) == 's') || (std::tolower(mat[i - 1][j + 1]) == 's' && std::tolower(mat[i + 1][j - 1]) == 'm'))) {
                    total++;
                }
            }
        }
    }

    std::cout << total << std::endl;

    return 0;
}
