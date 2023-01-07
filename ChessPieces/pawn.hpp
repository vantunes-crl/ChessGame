#ifndef PAWN_HPP
#define PAWN_HPP
#pragma once

#include "queen.hpp"

/**
 * @brief Class that represents the Pawn in Chess Game.
 * Can move 2 places in the first play.
 * Can move just 1 place after the first play.
 * Can move Diagonal if can kill someone in that place.
 */
class pawn : public Ichess_pieces
{
    public:
        int play(Board &Board, int ToMoveint) override;
        int type() override;
        int getPos(Board &Board) const override;
        bool getColor() const override;

        /**
         * @brief Construct a new Pawn object
         * 
         * @param b Chess Piece Color False/Black True/White
         */
        pawn(bool b);

        std::shared_ptr<Ichess_pieces> copy() override;
        int Check(Board &Board, int ToMovePos) override;

    private:
        bool Color;
        BackTrack backTrack;
        bool first_play = true;
        bool checkEnd(const int ToMovePos);
        bool enpassante = false;
        void move(std::shared_ptr<Ichess_pieces> &ToMovePos, std::shared_ptr<Ichess_pieces> &Pos, bool end);
};


#endif