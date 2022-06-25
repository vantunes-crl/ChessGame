#ifndef HORSE_HPP
#define HORSE_HPP
#pragma once
#include "Ichess_pieces.hpp"

/**
 * @brief Class that represents the Horse in Chess Game.
 * Can move only in L two vertical/horizontal one vertical/horizontal.
 */
class horse : public Ichess_pieces
{
    public:
        int play(Table_t &Table, Pos ToMovePos) override;
        int type() override;
        Pos getPos(Table_t &Table) const override;
        bool getColor() const override;

        /**
         * @brief Construct a new Horse object
         * 
         * @param b Chess Piece Color False/Black True/White
         */
        horse(bool b);
        std::shared_ptr<Ichess_pieces> copy() override;
    private:
        bool Color;
};

#endif

