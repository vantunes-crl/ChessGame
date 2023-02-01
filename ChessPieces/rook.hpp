#ifndef ROOK_HPP
#define ROOK_HPP

#include "king.hpp"

/**
 * @brief Class that represents the rook in Chess Game.
 * Can move only Horizontal or Vertical.
 * No move limit.
 */

class rook : public Ichess_pieces
{
    public:
        int play(Board &Board, const int &ToMoveInt) override;
        int type() const override;
        int getPos(Board &Board) const override;
        bool getColor() const override;

        /**
         * @brief Construct a new rook object
         * 
         * @param b  Chess Piece Color False/Black True/White
         */
         explicit rook(COLORS b);

        int Check(Board &Board, const int &ToMovePos) override;
    private:
        bool Color;
        BackTrack backTrack;
        std::list<int> moves;
        bool swap;
        bool swapKing(Board &Board, const int &posRook, const int &posKing);

};

#endif