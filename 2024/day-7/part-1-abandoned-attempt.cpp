#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool test(int target, std::vector<int> nums, std::vector<int> operators) {
    int total = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        operators[i - 1] == 0 ? total += nums[i] : total *= nums[i];
    }
    if (total == target) {
        return true;
    }
    int last1 = -1;
    for (int i = operators.size() - 1; i >= 0; i--) {
        if (operators[i] == 1) {
            last1 = i;
        }
    }
    if (last1 == -1) {
        operators[operators.size() - 1] = 1;
        return test(target, nums, operators);
    }
    int secondLast1 = -1;
    bool done1 = false;
    for (int i = operators.size() - 1; i >= 0; i--) {
        if (operators[i] == 1) {
            if (!done1) {
                done1 = true;
            } else {
                secondLast1 = i;
            }
        }
    }
    bool all1 = true;
    for (int i = 0; i < operators.size(); i++) {
        if (operators[i] == 0) {
            all1 = false;
            break;
        }
    }
    if (all1) {
        return false;
    } else if (last1 == secondLast1 + 1) {
        operators[last1 - 1] = 1;
        operators[operators.size() - 1] = 1;
    } else {
        operators[last1] = 0;
        operators[last1 - 1] = 1;
    }
    return test(target, nums, operators);
}

int main() {
  std::ifstream ifs("sample-input.txt");
  std::string line;
  int total = 0;

  while (std::getline(ifs, line)) {
    int target = std::stoi(line.substr(0, line.find(":")));
    line = line.substr(line.find(":") + 2, line.length());
    std::istringstream iss(line);
    int n;
    std::vector<int> nums;
    while (iss >> n) {
      nums.push_back(n);
    }
    std::vector<int> operators;
    for (int i = 0; i < nums.size() - 1; i++) {
        operators.push_back(0);
    }
    if (test(target, nums, operators)) {
        total += target;
    }
  }
}