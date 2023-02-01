#ifndef KING_HPP
#define KING_HPP

#pragma once
#include "Ichess_pieces.hpp"
#include <memory>


/**
 * @brief Class that represents the king in Chess Game.
 * Can move one place to all directions.
 * Can't move if can be killed in the next place.
 * Most important Piece of the game, if king die the game ends.
 */
class king : public Ichess_pieces 
{
    public:
        int play(Board &Board, const int &ToMoveInt) override;
        int type() const override;
        int getPos(Board &Board) const override;
        bool getColor() const override;

        /**
         * @brief Construct a new King object
         * 
         * @param b Chess Piece Color False/Black True/White
         */
        explicit king(COLORS b);

        int Check(Board &Board, const int &ToMovePos) override;

    private:
        bool Color;
        BackTrack backTrack;
        const int AvalPos[8] = {-1, 1, 8, -8, 7, -7, 9, -9};

        /**
         * @brief Check the next position, if someone can kill there.
         * 
         * @param Board Board where the pieces are.
         * @param pos the next pos to move.
         * @return true if can be killed.
         * @return false if no one can kill.
         */
        bool checkIfSomeoneCanKill(Board &Board, const int &pos);

};



#endif