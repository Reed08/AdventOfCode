#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

bool isValid(long long target, const std::vector<long long> &nums)
{
    int numOperators = nums.size() - 1;
    long maxCombinations = 1L << numOperators;

    for (long combination = 0; combination < maxCombinations; combination++)
    {
        long long total = nums[0];

        for (int op = 0; op < numOperators; op++)
        {
            if (combination & (1 << op))
            {
                total *= nums[op + 1];
            }
            else
            {
                total += nums[op + 1];
            }
        }

        if (total == target)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::ifstream ifs("input.txt");
    std::string line;
    long long total = 0;

    while (std::getline(ifs, line))
    {
        long long target = std::stoll(line.substr(0, line.find(":")));
        line = line.substr(line.find(":") + 2);
        std::istringstream iss(line);
        long long n;
        std::vector<long long> nums;
        while (iss >> n)
        {
            nums.push_back(n);
        }
        if (isValid(target, nums))
        {
            total += target;
        }
    }

    std::cout << total << std::endl;
}