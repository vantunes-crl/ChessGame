#ifndef ICHESS_PIECES_HPP
#define ICHESS_PIECES_HPP
#pragma once

#include <iostream>
#include <memory>
#include "../BackTrackAlgorithm/BackTrack.hpp"
#include <algorithm>
#include "../Board.hpp"

class Board;
/**
 * @brief Type of each piece in chess game.
 * 
 */
enum PIECES {
    EMPTY,
    WHITE_BISHOP,
    WHITE_HORSE,
    WHITE_KING,
    WHITE_PAWN,
    WHITE_QUEEN,
    WHITE_ROOK,
    BLACK_BISHOP,
    BLACK_HORSE,
    BLACK_KING,
    BLACK_PAWN,
    BLACK_QUEEN,
    BLACK_ROOK,
};

/**
 * @brief Type of each Error for debug. 
 * 
 */
enum ERRORS {
    NO_ERROR,
    OUT_SIZE,
    SAME_PLACE,
    GO_BACK,
    CANT_MOVE,
    LIMIT_MOVES,
    SWAP_KING,
    ENPASSANTE,
};

/**
 * @brief Interface to build all Pieces on the Chess Game.
 * 
 */
class Ichess_pieces
{
    public:
        /**
         * @brief Move a piece on the Board.
         * 
         * @param Board Board where the pieces are.
         * @param ToMovePos int pos to the next move based in a 64 pos board.
         * @return int > 0 if an error occurs, else return 0.
         */
        virtual int play(Board &Board, int ToMovePos) = 0;


        virtual int Check(Board &Board, int ToMovePos) = 0;
        /**
         * @brief Get the int of the piece on the Board.
         * 
         * @param Board Board where the pieces are.
         * @return int pos to the next move based in a 64 pos board.
         */
        virtual int getPos(Board &Board) const = 0;
        /**
         * @brief Type of the pieces
         * 
         * @return a int value based on an enum structure (PIECES).
         */
        virtual int type() = 0;
        /**
         * @brief Get the Color of object
         * 
         * @return true White
         * @return false Black
         */
        virtual bool getColor() const = 0;
        /**
         * @brief Create a Copy of the piece.
         * 
         * @return std::shared_ptr<Ichess_pieces> 
         */
        virtual std::unique_ptr<Ichess_pieces> copy() = 0;
        virtual ~Ichess_pieces() {};

};


#endif