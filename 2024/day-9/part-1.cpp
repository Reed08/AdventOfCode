#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::ifstream ifs("input.txt");
    std::string line;
    std::vector<int> diskMap;

    std::getline(ifs, line);

    int diskNum = 0;
    for (int i = 0; i < line.length(); i++)
    {
        int numDigits = std::stoi(line.substr(i, 1));
        if (i % 2 == 0)
        {
            for (int j = 0; j < numDigits; j++)
            {
                diskMap.push_back(diskNum);
            }
            diskNum++;
        }
        else
        {
            for (int j = 0; j < numDigits; j++)
            {
                diskMap.push_back(-1);
            }
        }
    }

    int firstIndex = 0;
    for (int i = diskMap.size() - 1; i >= 0; i--)
    {
        for (int j = firstIndex; j < i; j++)
        {
            if (diskMap[j] == -1)
            {
                firstIndex = j;
                diskMap[j] = diskMap[i];
                diskMap[i] = -1;
                break;
            }
        }
    }

    long long total = 0;
    for (int i = 1; i < diskMap.size() && diskMap[i] != -1; i++)
    {
        std::cout << diskMap[i] << " * " << i << std::endl;
        total += diskMap[i] * i;
    }

    std::cout << total << std::endl;
}