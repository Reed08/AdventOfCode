#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::string line;
    std::ifstream ifs("input.txt");
    bool part2 = false;
    std::vector<int> keys;
    std::vector<int> values;
    int total = 0;

    while(std::getline(ifs, line)) {
        if (line.empty()) {
            part2 = true;
            continue;
        }

        if (!part2) {
            std::string k;
            std::string v;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == '|') {
                    k = line.substr(0, i);
                    v = line.substr(i + 1, line.length());
                    break;
                }
            }
            keys.push_back(std::stoi(k));
            values.push_back(std::stoi(v));
        } else {
            std::vector<int> vals;
            size_t pos = 0;
            std::string token;
            while ((pos = line.find(",")) && pos != std::string::npos) {
                token = line.substr(0, pos);
                if (!token.empty()) {
                    vals.push_back(std::stoi(token));
                }
                line.erase(0, pos + 1);
            }

            bool isGood = true;
            if (!line.empty()) {
                vals.push_back(std::stoi(line));
            }

            for (int i = 0; i < vals.size(); i++) {
                for (int j = 0; j < keys.size(); j++) {
                    if (keys[j] == vals[i]) {
                        for (int k = 0; k < i; k++) {
                            if (vals[k] == values[j]) {
                                isGood = false;
                                break;
                            }
                        }
                        if (!isGood) {
                            break;
                        }
                    }
                }
            }

            if (isGood) {
                std::cout << "Adding: " << vals[vals.size() / 2] << " for " << line << std::endl;
                total += vals[vals.size() / 2];
            }
        }
    }

    std::cout << total << std::endl;

    return 0;
}
