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

    // check horizontal forward matches
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size() - 3; j++) {
            if (std::tolower(mat[i][j]) == 'x' && std::tolower(mat[i][j + 1]) == 'm' && std::tolower(mat[i][j + 2]) == 'a' && std::tolower(mat[i][j + 3]) == 's') {
                total++;
            }
        }
    }

    // check horizontal backward matches
    for (int i = 0; i < mat.size(); i++) {
        for (int j = mat[i].size() - 1; j >= 3; j--) {
            if (std::tolower(mat[i][j]) == 'x' && std::tolower(mat[i][j - 1]) == 'm' && std::tolower(mat[i][j - 2]) == 'a' && std::tolower(mat[i][j - 3]) == 's') {
                total++;
            }
        }
    }

    // check vertical forward matches
    for (int i = 0; i < mat[0].size(); i++) {
        for (int j = 0; j < mat.size() - 3; j++) {
            if (std::tolower(mat[j][i]) == 'x' && std::tolower(mat[j + 1][i]) == 'm' && std::tolower(mat[j + 2][i]) == 'a' && std::tolower(mat[j + 3][i]) == 's') {
                total++;
            }
        }
    }

    // check vertical backward matches
    for (int i = 0; i < mat[0].size(); i++) {
        for (int j = mat.size() - 1; j >= 3; j--) {
            if (std::tolower(mat[j][i]) == 'x' && std::tolower(mat[j - 1][i]) == 'm' && std::tolower(mat[j - 2][i]) == 'a' && std::tolower(mat[j - 3][i]) == 's') {
                total++;
            }
        }
    }

    // check diagonal downward right (+ +) matches
    for (int i = 0; i < mat[0].size() - 3; i++) {
        for (int j = 0; j < mat.size() - 3; j++) {
            if (std::tolower(mat[i][j]) == 'x' && std::tolower(mat[i + 1][j + 1]) == 'm' && std::tolower(mat[i + 2][j + 2]) == 'a' && std::tolower(mat[i + 3][j + 3]) == 's') {
                total++;
            }
        }
    }

    // check diagonal downward left (+ -) matches
    for (int i = 0; i < mat[0].size() - 3; i++) {
        for (int j = 3; j < mat.size(); j++) {
            if (std::tolower(mat[i][j]) == 'x' && std::tolower(mat[i + 1][j - 1]) == 'm' && std::tolower(mat[i + 2][j - 2]) == 'a' && std::tolower(mat[i + 3][j - 3]) == 's') {
                total++;
            }
        }
    }

    // check diagonal upward right (- +) matches
    for (int i = 3; i < mat[0].size(); i++) {
        for (int j = 0; j < mat.size() - 3; j++) {
            if (std::tolower(mat[i][j]) == 'x' && std::tolower(mat[i - 1][j + 1]) == 'm' && std::tolower(mat[i - 2][j + 2]) == 'a' && std::tolower(mat[i - 3][j + 3]) == 's') {
                total++;
            }
        }
    }

    // check diagonal upward left (- -) matches
    for (int i = 3; i < mat[0].size(); i++) {
        for (int j = 3; j < mat.size(); j++) {
            if (std::tolower(mat[i][j]) == 'x' && std::tolower(mat[i - 1][j - 1]) == 'm' && std::tolower(mat[i - 2][j - 2]) == 'a' && std::tolower(mat[i - 3][j - 3]) == 's') {
                total++;
            }
        }
    }

    std::cout << total << std::endl;

    return 0;
}
