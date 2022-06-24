#ifndef ICHESS_PIECES_HPP
#define ICHESS_PIECES_HPP
#pragma once

#include <iostream>
#include "table.hpp"
#include <memory>

struct Pos
{
    Pos(int x, int y) :x(x), y(y) {}
    int x;
    int y;
};

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

enum ERRORS {
    NO_ERROR,
    OUT_SIZE,
    SAME_PLACE,
    GO_BACK,
    CANT_MOVE,
    LIMIT_MOVES,
};

class Ichess_pieces
{
    public:
        typedef table<std::shared_ptr<Ichess_pieces>> Table_t;
    public:
        virtual int play(Table_t &Table, Pos ToMovePos) = 0;
        virtual Pos getPos(Table_t &Table) const = 0;
        virtual int type() = 0;
        virtual bool getColor() const = 0;
        virtual std::shared_ptr<Ichess_pieces> copy() = 0;
        virtual ~Ichess_pieces() {};
};


#endif