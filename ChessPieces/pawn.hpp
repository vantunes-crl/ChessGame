#ifndef PAWN_HPP
#define PAWN_HPP

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
        int play(Board &Board, const int &ToMoveInt) override;
        int type() const override;
        int getPos(Board &Board) const override;
        bool getColor() const override;

        /**
         * @brief Construct a new Pawn object
         * 
         * @param b Chess Piece Color False/Black True/White
         */
        explicit pawn(COLORS b);

        int Check(Board &Board,const int &ToMovePos) override;

    private:
        COLORS Color;
        BackTrack backTrack;
        bool first_play = true;
        bool checkEnd(const int &ToMovePos);
        void move(std::unique_ptr<Ichess_pieces> &&ToMovePos, std::unique_ptr<Ichess_pieces> &&Pos, const bool &end);
};


#endif