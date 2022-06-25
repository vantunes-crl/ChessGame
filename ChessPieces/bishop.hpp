#ifndef BISHOP_HPP
#define BISHOP_HPP
#pragma once
#include "Ichess_pieces.hpp"

/**
 * @brief Class that represents the Bishop in Chess Game.
 * Can move only diagonal left/right.
 * Can move without limit.
 */
class bishop : public Ichess_pieces
{
    public:
        int play(Table_t &Table, Pos ToMovePos) override;
        int type() override;
        Pos getPos(Table_t &Table) const override;
        bool getColor() const override;

        /**
         * @brief Construct a new Bishop object
         * 
         * @param b Chess Piece Color False/Black True/White
         */
        bishop(bool b);
        std::shared_ptr<Ichess_pieces> copy() override;

    private:
        bool Color;
};




#endif