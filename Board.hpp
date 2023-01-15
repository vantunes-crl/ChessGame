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
 * @warning Use this Template with a diferent type of std::unique_ptr<Ichess_pieces> will cause undefine behavior
 */
class Ichess_pieces;

class Board
{
    public:

        void printTable();

        //Board &operator=(std::unique_ptr<Ichess_pieces> &Pieces);

        void saveState(std::string move, std::string color, int playNumber);

        std::array<double, 64> read_state();

        std::unique_ptr<Ichess_pieces> &operator[](const int i);

        void setMoveEvent(int move, bool arg);

        std::pair<int,bool> getLastEventMove();


    private:
        std::array<std::unique_ptr<Ichess_pieces>, 64> PlayBoard;
        std::list<std::pair<int, bool>> LogsMove;
};

#endif