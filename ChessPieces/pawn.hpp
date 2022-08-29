#ifndef PAWN_HPP
#define PAWN_HPP
#pragma once

#include "Ichess_pieces.hpp"
#include "../BackTrackAlgorithm/BackTrack.hpp"

/**
 * @brief Class that represents the Pawn in Chess Game.
 * Can move 2 places in the first play.
 * Can move just 1 place after the first play.
 * Can move Diagonal if can kill someone in that place.
 */
class pawn : public Ichess_pieces
{
    public:
        int play(Board_t &Board, int ToMoveint) override;
        int type() override;
        int getPos(Board_t &Board) const override;
        bool getColor() const override;

        /**
         * @brief Construct a new Pawn object
         * 
         * @param b Chess Piece Color False/Black True/White
         */
        pawn(bool b);

        std::shared_ptr<Ichess_pieces> copy() override;
    private:
        bool Color;
        BackTrack backtrack;
        bool checkEnd(const int ToMovePos);
        void move(std::shared_ptr<Ichess_pieces> &ToMovePos, std::shared_ptr<Ichess_pieces> &Pos, bool end);
};


#endif