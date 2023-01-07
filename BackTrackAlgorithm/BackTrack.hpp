#pragma once

#include <list>
#include "../Board.hpp"

class Board;

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
         * @param Board Board where all the pieces are.
         * @return std::list<int> with all int X/Y where this piece can move.
         */
        std::list<int> BackTrackAvalPlacesList(const int &PiecesPos, Board &board);

         /**
         * @brief search for all possible moves of the piece on the table and print.
         * 
         * @param PiecesPos int of the piece to be verify in the table.
         * @param Board Board where all the pieces are.
         */
        void BackTrackAvalPlacesPrint(const int &Piecesint, Board &board);

        /**
         * @brief Check avalivable places between a distance in steps.
         * 
         * as the chess has a representatation of 64 numbers, this function can be used to check
         * places where the all piece can go.
         * Example:
         * Rook can only move in vertical or horizontal.
         * 
         * 00 | 01 | 02 | 03 | 04 | 05 | 06 | 07 
         * 08 | 09 | 10 | 11 | 12 | 13 | 14 | 15 
         * 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 
         * 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31...
         * 
         * +8 he moves 1 step vertical
         * +1 he moves 1 step horizontal
         * 
         * @param steps value in steps to check.
         * @param Edge Edges are used to stop the piece to go outsize of the board.
         * Example:
         * if Rook moves +1 steps to the horizontal he need stop at Right Edge. TOP_EDGE, BOTTON_EDGE, LEFT_EDGE, RIGHT_EDGE.
         * @param pos Pos of the piece.
         * @param Board Board where all the pieces are. 
         * @param moves 
         */
        void AvalMoves(int steps, EDGES Edge, int pos, Board &board, std::list<int> &moves);

        /**
         * @brief Check the edges to handle some bugs where the piece cross the board.
         * 
         * @param pos Piece pos.
         * @param ToMovePos Next position to move.
         * @return true if piece will move to the same edge.
         * @return false if the piece try to move to the other edge of the board.
         */
        bool checkOpositeEdges(const int &pos, const int &ToMovePos);
};