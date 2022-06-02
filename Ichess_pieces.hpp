#ifndef ICHESS_PIECES_HPP
#define ICHESS_PIECES_HPP

#include <iostream>
#include "table.hpp"

struct Pos
{
    Pos(int x, int y):x(x), y(y) {}
    int x;
    int y;
};

enum PIECES
{
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

class Ichess_pieces
{
    protected:
        bool Color;
    public:
        virtual void play(table<Ichess_pieces *> &Table, int x, int y) = 0;
        virtual Pos getPos(table<Ichess_pieces *> &Table) const = 0;
        virtual PIECES type() = 0;
        virtual bool getColor() { return Color; };
        

    virtual ~Ichess_pieces() {};
};


#endif