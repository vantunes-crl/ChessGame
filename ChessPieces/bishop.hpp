#ifndef BISHOP_HPP
#define BISHOP_HPP
#include "Ichess_pieces.hpp"

/**
 * @brief Class that represents the Bishop in Chess Game.
 * Can move only diagonal left/right.
 * Can move without limit.
 */
class bishop : public Ichess_pieces
{
    public:
        int play(Board &Board, const int &ToMovePos) override;
        int type() const override;
        int getPos(Board &Board) const override;
        bool getColor() const override;
        int Check(Board &Board, const int &ToMovePos) override;

        /**
         * @brief Construct a new Bishop object
         * 
         * @param b Chess Piece Color False/Black True/White
         */
        explicit bishop(COLORS b);

    private:
        bool Color;
        std::list<int> moves;
        BackTrack backTrack;

};

#endif