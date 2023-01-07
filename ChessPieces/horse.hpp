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
        int play(Board &Board, int ToMoveint) override;
        int type() override;
        int getPos(Board &Board) const override;
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
        BackTrack backTrack;

        /**
         * @brief Check Distance between Ys to handle errors.
         * 
         * @param pos Pos of the piece.
         * @param ToMovePos Pos to move.
         * @return true if the distance is less than 3.
         * @return false if the distance is bigger than 3.
         */
        bool checkDistance(int pos, int ToMovePos);
};

#endif

