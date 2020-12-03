#include "aoc_1.h"

#include <iostream>
#include <fstream>
#include <algorithm>

std::vector<int> parseFile(const std::string filename)
{
    std::vector<int> list;

    std::ifstream file{filename};

    std::string line;
    while (std::getline(file, line))
    {
        list.push_back(std::stoi(line));
    }

    return list;
}

std::pair<int, int> findSum(const std::string filename)
{
    auto int_list = parseFile(filename);

    std::sort(int_list.begin(), int_list.end());

    std::pair<int, int> return_pair;

    auto it_begin = int_list.begin();
    auto it_end = int_list.end();

    while (it_begin != it_end)
    {
        const int current_sum = *it_begin + *it_end;
        if (current_sum < 2020)
        {
            ++it_begin;
        }
        else if (current_sum > 2020)
        {
            --it_end;
        }
        else
        {
            return_pair.first = *it_begin;
            return_pair.second = *it_end;
            return return_pair;
        }
    }

    return return_pair;
}
