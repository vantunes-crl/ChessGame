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
        int play(Table_t &Table, Pos ToMovePos) override;
        int type() override;
        Pos getPos(Table_t &Table) const override;
        bool getColor() const override;

        /**
         * @brief Construct a new queen object
         * 
         * @param b  Chess Piece Color False/Black True/White
         */
        queen(bool b);
        std::shared_ptr<Ichess_pieces> copy() override;
    private:
        bool Color;
};

#endif