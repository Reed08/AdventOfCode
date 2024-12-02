#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main() {
    std::ifstream input("input.txt");
    std::string line;

    int safeReports = 0;

    while (std::getline(input, line)) {
        bool isSafe = true;
        bool ascending;
        std::vector<int> nums;
        int n;
        std::istringstream iss(line);
        // iss >> n;
        // lastN = n;
        // iss >> n;
        // if (n > lastN) {
        //     ascending = true;
        // } else {
        //     ascending = false;
        // }
        // if ((std::abs(n - lastN) < 1) || (std::abs(n - lastN) > 3)) {
        //     numBadLevels++;
        //     std::cout << "UNSAFE - last: " << lastN << ", current: " << n << std::endl;
        // } else {
        //     std::cout << "SAFE - last: " << lastN << ", current: " << n << std::endl;
        //     lastN = n;
        // }
        // int iter = 0;
        while (iss >> n) {
            // if (numBadLevels > 1) break;
            // if (iter == 0 && numBadLevels == 1) {
            //     if (n > lastN) {
            //         ascending = true;
            //     } else {
            //         ascending = false;
            //     }
            // }
            // if ((ascending && n < lastN) || (!ascending && n > lastN) || (std::abs(n - lastN) < 1) || (std::abs(n - lastN) > 3)) {
            //     numBadLevels++;
            //     std::cout << "UNSAFE - last: " << lastN << ", current: " << n << std::endl;
            // } else {
            //     std::cout << "SAFE - last: " << lastN << ", current: " << n << std::endl;
            //     lastN = n;
            // }
            // iter++;
            nums.push_back(n);
        }

        ascending = nums[1] > nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if ((ascending && nums[i] < nums[i - 1]) || (!ascending && nums[i] > nums[i - 1]) || (std::abs(nums[i] - nums[i - 1]) < 1) || (std::abs(nums[i] - nums[i - 1]) > 3)) {
                isSafe = false;
                std::cout << "UNSAFE - last: " << nums[i - 1] << ", current: " << nums[i] << std::endl;
            } else {
                std::cout << "SAFE - last: " << nums[i - 1] << ", current: " << nums[i] << std::endl;
            }
        }

        if (isSafe) {
            safeReports++;
            std::cout << "SAFE!!" << std::endl;
        } else {
            for (int i = 0; i < nums.size(); i++) {
                std::vector<int> newNums;
                for (int j = 0; j < nums.size(); j++) {
                    if (j != i) newNums.push_back(nums[j]);
                }
                isSafe = true;
                ascending = newNums[1] > newNums[0];
                for (int j = 1; j < newNums.size(); j++) {
                    if ((ascending && newNums[j] < newNums[j - 1]) || (!ascending && newNums[j] > newNums[j - 1]) || (std::abs(newNums[j] - newNums[j - 1]) < 1) || (std::abs(newNums[j] - newNums[j - 1]) > 3)) {
                        isSafe = false;
                        std::cout << "UNSAFE - last: " << newNums[j - 1] << ", current: " << newNums[j] << std::endl;
                    } else {
                        std::cout << "SAFE - last: " << newNums[j - 1] << ", current: " << newNums[j] << std::endl;
                    }
                }
                if (isSafe) break;
            }
            if (isSafe) {
                safeReports++;
                std::cout << "SAFE!!" << std::endl;
            } else {
                std::cout << "UNSAFE!!" << std::endl;
            }
        }
    }
    std::cout << safeReports << std::endl;
}
