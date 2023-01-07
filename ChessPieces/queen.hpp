#ifndef QUEEN_HPP
#define QUEEN_HPP

#pragma once
#include "Ichess_pieces.hpp"

/**
 * @brief Class that represents the king in Chess Game.
 * Can move Diagonal left/right Vertical/Horizontal
 * No move limit.
 */
class queen : public Ichess_pieces
{
    public:
        int play(Board &Board, int ToMoveint) override;
        int type() override;
        int getPos(Board &Board) const override;
        bool getColor() const override;

        int Check(Board &Board, int ToMovePos) override;

        /**
         * @brief Construct a new queen object
         * 
         * @param b  Chess Piece Color False/Black True/White
         */
        queen(bool b);
        std::shared_ptr<Ichess_pieces> copy() override;
    private:
        bool Color;
        std::list<int> moves;
        BackTrack backTrack;
};

#endif