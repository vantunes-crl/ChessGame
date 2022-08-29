#pragma once

#include "../ChessPieces/Ichess_pieces.hpp"

enum DIAGONAL_CHECK_CASE {
    DIAGONAL_TOP_LEFT,
    DIAGONAL_TOP_RIGHT,
    DIAGONAL_BOTTOM_LEFT,
    DIAGONAL_BOTTOM_RIGHT,
};

enum VERTICAL_CHECK_CASE {
    VERTICAL_TOP,
    VERTICAL_BOTTOM,
};

enum HORIZONTAL_CHECK_CASE {
    HORIZONTAL_LEFT,
    HORIZONTAL_RIGHT
};

enum EDGES
 {
    TOP_EDGE, BOTTON_EDGE, LEFT_EDGE, RIGHT_EDGE
 };


/**
 * @brief Class to calculate all possible moves and checks in a Chess Game.
 * 
 */
class BackTrack
{
    public:
        /**
         * @brief search for all possible moves of the piece on the table.
         * 
         * @param PiecesPos int of the piece to be verify in the table.
         * @param Board Board where the piece is.
         * @return std::list<int> with all int X/Y where this piece can move.
         */
        std::list<int> BackTrackAvalPlacesList(const int &PiecesPos, Ichess_pieces::Board_t &Board);
         /**
         * @brief search for all possible moves of the piece on the table and print.
         * 
         * @param PiecesPos int of the piece to be verify in the table.
         * @param Board Board where the piece is.
         */
        void BackTrackAvalPlacesPrint(const int &Piecesint, Ichess_pieces::Board_t &Board);

        void AvalMoves(int steps, EDGES Edge, int pos, Ichess_pieces::Board_t &Board, std::list<int> &moves);

        bool checkOpositeEdges(const int &pos, const int &ToMovePos);

};