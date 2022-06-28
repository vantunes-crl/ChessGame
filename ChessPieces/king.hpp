#ifndef KING_HPP
#define KING_HPP
#pragma once
#include "Ichess_pieces.hpp"
#include "../BackTrackAlgorithm/BackTrack.hpp"

/**
 * @brief Class that represents the king in Chess Game.
 * Can move one place to all directions.
 * Can't move if can be killed in the next place.
 * Most important Piece of the game, if king die the game ends.
 */
class king : public Ichess_pieces 
{
    public:
        int play(Table_t &Table, Pos ToMovePos) override;
        int type() override;
        Pos getPos(Table_t &Table) const override;
        bool getColor() const override;

        /**
         * @brief Construct a new King object
         * 
         * @param b Chess Piece Color False/Black True/White
         */
        king(bool b);
        std::shared_ptr<Ichess_pieces> copy() override;
        bool checkIfSomeoneCanKill(Ichess_pieces::Table_t Table, Pos pos);
    private:
        bool Color;
        BackTrack backTrack;

};



#endif