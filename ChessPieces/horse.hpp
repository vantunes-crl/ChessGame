#ifndef HORSE_HPP
#define HORSE_HPP
#include "Ichess_pieces.hpp"

/**
 * @brief Class that represents the Horse in Chess Game.
 * Can move only in L two vertical/horizontal one vertical/horizontal.
 */
class horse : public Ichess_pieces
{
    public:
        int play(Board &Board, const int &ToMoveint) override;
        int type() const override;
        int getPos(Board &Board) const override;
        bool getColor() const override;
        int Check(Board &Board, const int &ToMovePos) override;

        /**
         * @brief Construct a new Horse object
         * 
         * @param b Chess Piece Color False/Black True/White
         */
        explicit horse(COLORS b);

    private:
        bool Color;
        BackTrack backTrack;
        const int AvalPos[8] = {17, -17, 15, -15, 6, -6, 10, -10};

        /**
         * @brief Check Distance between Ys to handle errors.
         * 
         * @param pos Pos of the piece.
         * @param ToMovePos Pos to move.
         * @return true if the distance is less than 3.
         * @return false if the distance is bigger than 3.
         */
        static bool checkDistance(const int &pos, const int &ToMovePos);
};

#endif

