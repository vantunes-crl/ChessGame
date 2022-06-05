#ifndef ICHESS_PIECES_HPP
#define ICHESS_PIECES_HPP

#include <iostream>
#include "table.hpp"

struct Pos
{
    int x;
    int y;
};

enum PIECES {
    WHITE_BISHOP,
    WHITE_HORSE,
    WHITE_KING,
    WHITE_KNIGHT,
    WHITE_PAWN,
    WHITE_QUEEN,
    WHITE_ROOK,
    BLACK_BISHOP,
    BLACK_HORSE,
    BLACK_KING,
    BLACK_KNIGHT,
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
    protected:
        bool Color;
    public:
        virtual int play(table<Ichess_pieces *> &Table, int x, int y) = 0;
        virtual Pos getPos(table<Ichess_pieces *> &Table) const = 0;
        virtual int type() = 0;
        virtual bool getColor() { return Color; };
        

    virtual ~Ichess_pieces() {};
};


#endif