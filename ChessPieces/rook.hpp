#ifndef ROOK_HPP
#define ROOK_HPP
#pragma once
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
        int play(Table_t &Table, Pos ToMovePos) override;
        int type() override;
        Pos getPos(Table_t &Table) const override;
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
        BackTrack backtrack;

};

#endif