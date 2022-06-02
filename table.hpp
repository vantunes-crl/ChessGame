#ifndef TABLE_HPP
#define TABLE_HPP

#include <array>
#include <iostream>
#include <iomanip>

template <class T>
class table
{
private:
    std::array<std::array<T, 8>, 8> PlayTable;
public:
    void printTable()
    {
        std::array<std::string, 7> Pieces = {"Bishop", "Horse", "King", "Knight", "Pawn", "Queen", "Rook"};
        for (int i = 0; i < 8; ++i )
        {
            for (int j = 0; j < 8; ++j )
            {
                std::cout << std::left << std::setw(10) << std::setfill(' ');
                if (PlayTable[i][j])
                    std::cout << Pieces[PlayTable[i][j]->type()];
                else
                    std::cout << "null";
            }
            std::cout << std::endl;
            std::cout << std::left << "--------------------------------------------------------------------------" << std::endl;
        }
    }

    std::array<T, 8> &operator[](const int i) { return PlayTable[i]; }

    ~table() 
    {
        for (auto pieces : PlayTable)
        {
            for (auto piece : pieces)
            {
                if (piece)
                    delete piece;
            }
        }
    };

};


#endif