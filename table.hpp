#ifndef TABLE_HPP
#define TABLE_HPP

#include "pawn.hpp"
#include <array>
#include <iostream>

template <class T>
class table
{
private:
    std::array<std::array<T,8>, 8> PlayTable;
public:
    void printTable()
    {
        for (int i = 0; i < 8; ++i )
        {
            for (int j = 0; j < 8; ++j )
            {
                PlayTable[i][j] = new pawn;
                PlayTable[i][j]->play();
            }
            std::cout << std::endl;
        }
    }

    std::array<int, 8> &operator[](const int i) { return PlayTable[i]; }

    table() {};
    ~table() {};

};


#endif