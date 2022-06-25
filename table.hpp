#ifndef TABLE_HPP
#define TABLE_HPP
#pragma once

#include <array>
#include <iomanip>
#include <iostream>
#include <list>
#include <memory>

/**
 * @brief Class that represents the table in the Chess Game.
 * 
 * @tparam T std::shared_ptr<Ichess_pieces>
 * 
 * @warning Use this Template with a diferent type of std::shared_ptr<Ichess_pieces> will cause undefine behavior
 */
template <class T>
class table
{
    public:
        /**
         * @brief Print the table and the pieces with diferent colors.
         * 
         */
        void printTable()
        {
            std::array<std::string, 12> Pieces = {"\033[1;39mBishop\033[0m", "\033[1;39mHorse\033[0m",
            "\033[1;39mKing\033[0m", "\033[1;39mPawn\033[0m",
            "\033[1;39mQueen\033[0m", "\033[1;39mRook\033[0m",
            "\033[1;30mBishop\033[0m", "\033[1;30mHorse\033[0m",
            "\033[1;30mKing\033[0m", "\033[1;30mPawn\033[0m",
            "\033[1;30mQueen\033[0m", "\033[1;30mRook\033[0m"};
            for (int i = 0; i < 8; ++i )
            {
                for (int j = 0; j < 8; ++j )
                {
                    std::cout << std::left << std::setw(20) << std::setfill(' ');
                    if (PlayTable[i][j])
                        std::cout << Pieces[PlayTable[i][j]->type()];
                    else
                        std::cout << "\033[1;32mempty\033[0m";
                }
                std::cout << std::endl;
                std::cout << std::left << "--------------------------------------------------------------------------" << std::endl;
            }
        }

        std::array<T, 8> &operator[](const int i) { return PlayTable[i]; }

    private:
        std::array<std::array<T, 8>, 8> PlayTable;

};


#endif