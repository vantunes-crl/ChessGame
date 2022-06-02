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
    BISHOP,
    HORSE,
    KING,
    KNIGHT,
    PAWN,
    QUEEN,
    ROOK
};

class Ichess_pieces
{
    public:
        virtual void play(table<Ichess_pieces *> &Table, int x, int y) = 0;
        virtual Pos getPos(table<Ichess_pieces *> &Table) const = 0;
        virtual PIECES type() = 0;
        

    virtual ~Ichess_pieces() {};
};


#endif