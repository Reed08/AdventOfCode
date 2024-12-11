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

    std::vector<int> dontTouch;

    int contiguousFreeSpace = 0;
    std::vector<int> toMoveIndexes;
    toMoveIndexes.push_back(diskMap.size() - 1);
    int lastId = diskMap[diskMap.size() - 1];
    for (int i = diskMap.size() - 2; i >= 0; i--)
    {
        if (lastId == diskMap[i])
        {
            toMoveIndexes.push_back(i);
            continue;
        }

        bool shouldAdd = true;
        for (int j = 0; j < dontTouch.size(); j++)
        {
            for (int k = 0; k < toMoveIndexes.size(); k++) {
                if (dontTouch[j] == toMoveIndexes[k])
                {
                    shouldAdd = false;
                    break;
                }
            }
            if (!shouldAdd) break;
        }
        if (diskMap[toMoveIndexes[0]] == -1)
            shouldAdd = false;

        if (!shouldAdd)
        {
            toMoveIndexes.clear();
            toMoveIndexes.push_back(i);
            lastId = diskMap[i];
            continue;
        }

        for (int j = 0; j <= i + 1; j++)
        {
            if (diskMap[j] == -1)
            {
                contiguousFreeSpace++;
            }
            else
            {
                if (toMoveIndexes.size() > 0 && contiguousFreeSpace >= toMoveIndexes.size())
                {
                    int startingIndex = j - contiguousFreeSpace;
                    for (int k = startingIndex; k < startingIndex + toMoveIndexes.size(); k++)
                    {
                        diskMap[k] = diskMap[toMoveIndexes[0]];
                        dontTouch.push_back(k);
                    }
                    for (int index : toMoveIndexes)
                    {
                        diskMap[index] = -1;
                    }
                    break;
                }
                contiguousFreeSpace = 0;
            }
        }
        contiguousFreeSpace = 0;
        toMoveIndexes.clear();
        toMoveIndexes.push_back(i);
        lastId = diskMap[i];
    }

    long long total = 0;
    for (int i = 1; i < diskMap.size(); i++)
    {
        if (diskMap[i] == -1)
            continue;
        total += static_cast<long long>(diskMap[i]) * i;
    }

    std::cout << total << std::endl;
}
