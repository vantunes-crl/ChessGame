#ifndef ICHESS_PIECES_HPP
#define ICHESS_PIECES_HPP
#pragma once

#include <iostream>
#include "../table.hpp"
#include <memory>

/**
 * @brief Structure to save pos x and y.
 * 
 */
struct Pos
{
    Pos(int x, int y) :x(x), y(y) {}
    int x;
    int y;
};

/**
 * @brief Type of each piece in chess game.
 * 
 */
enum PIECES {
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
    BLACK_ROOK
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
};

/**
 * @brief Interface to build all Pieces on the Chess Game.
 * 
 */
class Ichess_pieces
{
    public:
        typedef table<std::shared_ptr<Ichess_pieces>> Table_t;
    public:
        /**
         * @brief Move a piece on the table.
         * 
         * @param Table Table where the pieces are.
         * @param ToMovePos Pos X,Y to the next move.
         * @return int > 0 if an error occurs, else return 0
         */
        virtual int play(Table_t &Table, Pos ToMovePos) = 0;
        /**
         * @brief Get the Pos of the piece on the table.
         * 
         * @param Table Table where the pieces are.
         * @return Pos X,Y in the table.
         */
        virtual Pos getPos(Table_t &Table) const = 0;
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
        virtual std::shared_ptr<Ichess_pieces> copy() = 0;
        virtual ~Ichess_pieces() {};
};


#endif