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
        int play(Board_t &Board, int ToMoveint) override;
        int type() override;
        int getPos(Board_t &Board) const override;
        bool getColor() const override;

        /**
         * @brief Construct a new King object
         * 
         * @param b Chess Piece Color False/Black True/White
         */
        king(bool b);
        std::shared_ptr<Ichess_pieces> copy() override;

    private:
        bool Color;
        BackTrack backTrack;
        /**
         * @brief Check the next position, if someone can kill there.
         * 
         * @param Board Board where the pieces are.
         * @param pos the next pos to move.
         * @return true if can be killed.
         * @return false if no one can kill.
         */
        bool checkIfSomeoneCanKill(Ichess_pieces::Board_t Board, int pos);

};



#endif