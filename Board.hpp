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
class Board 
{
    public:
        void printTable()
        {
            std::array<std::string, 12> Pieces = {
            "\033[1;39mBishop\033[0m", "\033[1;39mHorse\033[0m",
            "\033[1;39mKing\033[0m", "\033[1;39mPawn\033[0m",
            "\033[1;39mQueen\033[0m", "\033[1;39mRook\033[0m",
            "\033[1;30mBishop\033[0m", "\033[1;30mHorse\033[0m",
            "\033[1;30mKing\033[0m", "\033[1;30mPawn\033[0m",
            "\033[1;30mQueen\033[0m", "\033[1;30mRook\033[0m"
            };

            for (int i = 0; i < 64; ++i )
            {
                
                if (i % 8 == 0)
                    std::cout << std::left << "\n--------------------------------------------------------------------------\n";
                std::cout << std::left << std::setw(20) << std::setfill(' ');
                if (PlayBoard[i])
                    std::cout << Pieces[PlayBoard[i]->type()];
                else
                    std::cout << "\033[1;32mempty\033[0m";   
            }
            std::cout << std::left << "\n--------------------------------------------------------------------------\n";
        }

        Board operator=(const std::array<T, 64> &boardArray)
        {
            PlayBoard = boardArray;
            return *this;
        }

        bool &getFirstPlay(int color)
        {
            return first_play[color];
        }


        T &operator[](const int i) { return PlayBoard[i]; }

    private:
        std::array<T, 64> PlayBoard;
        bool first_play[2] = {true, true};

};


#endif