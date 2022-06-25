#pragma once

#include "../ChessPieces/Ichess_pieces.hpp"

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


        std::list<Pos> checkDiagonalTopLeft(Ichess_pieces::Table_t &Table, Pos StartPos);
        std::list<Pos> checkDiagonalTopRight(Ichess_pieces::Table_t &Table, Pos StartPos);
        std::list<Pos> checkDiagonalBottonLeft(Ichess_pieces::Table_t &Table, Pos StartPos);
        std::list<Pos> checkDiagonalBottonRight(Ichess_pieces::Table_t &Table, Pos StartPos);
};