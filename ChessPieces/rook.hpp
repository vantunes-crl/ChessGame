#ifndef ROOK_HPP
#define ROOK_HPP

#pragma once
#include "king.hpp"

/**
 * @brief Class that represents the rook in Chess Game.
 * Can move only Horizontal or Vertical.
 * No move limit.
 */

class rook : public Ichess_pieces
{
    public:
        int play(Board &Board, int ToMoveint) override;
        int type() override;
        int getPos(Board &Board) const override;
        bool getColor() const override;

        /**
         * @brief Construct a new rook object
         * 
         * @param b  Chess Piece Color False/Black True/White
         */
        rook(bool b);

        std::shared_ptr<Ichess_pieces> copy() override;
        int Check(Board &Board, int ToMovePos) override;
    private:
        bool Color;
        BackTrack backTrack;
        std::list<int> moves;
        bool swap = true;
        bool swapKing(Board &Board, const int posRook, const int posKing);

};

#endif