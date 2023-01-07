#ifndef TABLE_HPP
#define TABLE_HPP
#pragma once

#include <array>
#include <iomanip>
#include <iostream>
#include <list>
#include <memory>
#include <fstream>
#include "ChessPieces/Ichess_pieces.hpp"

/**
 * @brief Class that represents the table in the Chess Game.
 * 
 * 
 * @warning Use this Template with a diferent type of std::shared_ptr<Ichess_pieces> will cause undefine behavior
 */
class Ichess_pieces;

class Board
{
    public:

        void printTable();

        Board() = default;

        Board operator=(const std::array<std::shared_ptr<Ichess_pieces>, 64> &boardArray);

        bool &swapRookKing(int color);

        void saveState(std::string move, std::string color, int playNumber);

        std::array<int, 64> read_state();

        void swap_reset();

        std::shared_ptr<Ichess_pieces> &operator[](const int i);
        public:
            static Board *Board_;
        public:
            static Board *getInstance();

    private:
        std::array<std::shared_ptr<Ichess_pieces>, 64> PlayBoard;
        bool Swap[2] = {true, true};
};

#endif