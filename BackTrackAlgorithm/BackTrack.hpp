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
         * @param Piecesint int of the piece to be verify in the table.
         * @param Board Board where the piece is.
         * @return std::list<int> with all int X/Y where this piece can move.
         */
        std::list<int> BackTrackAvalPlacesList(const int &Piecesint, Ichess_pieces::Board_t &Board);
         /**
         * @brief search for all possible moves of the piece on the table and print.
         * 
         * @param Piecesint int of the piece to be verify in the table.
         * @param Board Board where the piece is.
         */
        void BackTrackAvalPlacesPrint(const int &Piecesint, Ichess_pieces::Board_t &Board);

        /**
         * @brief Check a especific diagonal in the Chess table.
         * 
         * @param Board Board where the piece is.
         * @param Startint Start position of the piece on the table.
         * @param CASE Case to check DIAGONAL_TOP_LEFT, DIAGONAL_TOP_RIGHT, DIAGONAL_BOTTON_RIGHT, DIAGONAL_BOTTON_RIGHT.
         * @return std::list<int> list of positions in that check.
         */
        std::list<int> checkDiagonal(Ichess_pieces::Board_t &Board, int Startint, const DIAGONAL_CHECK_CASE CASE);

        /**
         * @brief Check a especific horizontal on the Chess table.
         * 
         * @param Board Board where the piece is.
         * @param Startint Start position of the piece on the table.
         * @param CASE Case to check HORIZONTAL_LEFT, HORIZONTAL_RIGHT
         * @return std::list<int> list of positions in that check.
         */
        std::list<int> checkHorizontal(Ichess_pieces::Board_t &Board, int Startint, const HORIZONTAL_CHECK_CASE CASE);

         /**
         * @brief Check a especific vertical on the Chess table.
         * 
         * @param Board Board where the piece is.
         * @param Startint Start position of the piece on the table.
         * @param CASE Case to check VERTICAL_TOP, VERTICAL_BOTTON.
         * @return std::list<int> list of positions in that check.
         */
        std::list<int> checkVertical(Ichess_pieces::Board_t &Board, int Startint, const VERTICAL_CHECK_CASE CASE);

};