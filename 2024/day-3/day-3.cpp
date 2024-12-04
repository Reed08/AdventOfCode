#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main() {
    std::ifstream ifs("input.txt");

    int total = 0;

    std::string s;
    std::smatch m;
    std::regex e("mul\\(\\d*,\\d*\\)");
    bool isCounted = true;

    while (std::getline(ifs, s)) {
        while (std::regex_search(s, m, e)) {
            std::string result = m.str();
            std::string prefix = m.prefix();
            std::cout << "Match: " << result << std::endl;
            std::cout << "Prefix: " << prefix << std::endl;
            int lastDo = prefix.rfind("do()");
            int lastDont = prefix.rfind("don\'t()");
            if (!isCounted && lastDo != std::string::npos && lastDo > lastDont) {
                std::cout << "Setting isCounted to true" << std::endl;
                isCounted = true;
            } else if (isCounted && lastDont != std::string::npos && lastDont > lastDo) {
                std::cout << "Setting isCounted to false" << std::endl;
                isCounted = false;
            }

            if (isCounted) {
                int num1 = std::stoi(result.substr(4, result.find(",") - 4));
                int num2 = std::stoi(result.substr(result.find(",") + 1, result.size()));
                std::cout << "Adding product of " << num1 << " and " << num2 << std::endl;
                total += num1 * num2;
            }
            
            s = m.suffix().str();
        }
    }

    ifs.close();

    std::cout << total << std::endl;

    return 0;
}
