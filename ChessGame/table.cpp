#include "table.hpp"

table::table()
{
    initTable();
}

table::~table()
{
}

void table::printTable()
{
    for (auto table : ColorTable)
    {
        for (auto line : table)
            std::cout << line << " ";
        std::cout << std::endl;
    }
}


void table::initTable()
{
    for (auto i = 0; i < 8 ; ++i)
    {
        if (i % 2)
            ColorTable[i] = {0, 1, 0, 1, 0, 1, 0, 1};
        else
            ColorTable[i] = {1, 0, 1, 0, 1, 0, 1, 0};
    }
}

