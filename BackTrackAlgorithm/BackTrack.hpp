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
         * @param PiecesPos Pos of the piece to be verify in the table.
         * @param Table Table where the piece is.
         * @return std::list<Pos> with all Pos X/Y where this piece can move.
         */
        std::list<Pos> BackTrackAvalPlacesList(const Pos &PiecesPos, Ichess_pieces::Table_t &Table);
         /**
         * @brief search for all possible moves of the piece on the table and print.
         * 
         * @param PiecesPos Pos of the piece to be verify in the table.
         * @param Table Table where the piece is.
         */
        void BackTrackAvalPlacesPrint(const Pos &PiecesPos, Ichess_pieces::Table_t &Table);

        /**
         * @brief Check a especific diagonal in the Chess table.
         * 
         * @param Table Table where the piece is.
         * @param StartPos Start position of the piece on the table.
         * @param CASE Case to check DIAGONAL_TOP_LEFT, DIAGONAL_TOP_RIGHT, DIAGONAL_BOTTON_RIGHT, DIAGONAL_BOTTON_RIGHT.
         * @return std::list<Pos> list of positions in that check.
         */
        std::list<Pos> checkDiagonal(Ichess_pieces::Table_t &Table, Pos StartPos, const DIAGONAL_CHECK_CASE CASE);

        /**
         * @brief Check a especific horizontal on the Chess table.
         * 
         * @param Table Table where the piece is.
         * @param StartPos Start position of the piece on the table.
         * @param CASE Case to check HORIZONTAL_LEFT, HORIZONTAL_RIGHT
         * @return std::list<Pos> list of positions in that check.
         */
        std::list<Pos> checkHorizontal(Ichess_pieces::Table_t &Table, Pos StartPos, const HORIZONTAL_CHECK_CASE CASE);

         /**
         * @brief Check a especific vertical on the Chess table.
         * 
         * @param Table Table where the piece is.
         * @param StartPos Start position of the piece on the table.
         * @param CASE Case to check VERTICAL_TOP, VERTICAL_BOTTON.
         * @return std::list<Pos> list of positions in that check.
         */
        std::list<Pos> checkVertical(Ichess_pieces::Table_t &Table, Pos StartPos, const VERTICAL_CHECK_CASE CASE);

};