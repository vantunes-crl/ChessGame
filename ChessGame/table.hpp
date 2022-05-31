#ifndef TABLE_HPP
#define TABLE_HPP

#include <array>
#include <iostream>

class table
{
private:
    std::array<std::array<int, 8>, 8> ColorTable;
    std::array<std::array<int, 8>, 8> PlayTable;
public:
    void printTable();
    void initTable();

    std::array<int, 8> &operator[](const int i) { return ColorTable[i]; }

    table();
    virtual ~table();
};







#endif