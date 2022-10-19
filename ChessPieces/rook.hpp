#ifndef ROOK_HPP
#define ROOK_HPP
#pragma once
#include "king.hpp"
#include "Ichess_pieces.hpp"
#include "../BackTrackAlgorithm/BackTrack.hpp"
/**
 * @brief Class that represents the rook in Chess Game.
 * Can move only Horizontal or Vertical.
 * No move limit.
 */

class rook : public Ichess_pieces
{
    public:
        int play(Board_t &Board, int ToMoveint) override;
        int type() override;
        int getPos(Board_t &Board) const override;
        bool getColor() const override;

        /**
         * @brief Construct a new rook object
         * 
         * @param b  Chess Piece Color False/Black True/White
         */
        rook(bool b);

        std::shared_ptr<Ichess_pieces> copy() override;
    private:
        bool Color;
        BackTrack backTrack;
        bool swapKing(Board_t &Board, const int posRook, const int posKing);
        bool checkNullRange(Ichess_pieces *first, Ichess_pieces *end);

};

#endif