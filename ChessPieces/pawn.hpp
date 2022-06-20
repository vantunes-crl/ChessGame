#ifndef PAWN_HPP
#define PAWN_HPP
#pragma once


#include "../Ichess_pieces.hpp"

class pawn : public Ichess_pieces
{
    public:
        int play(table<Ichess_pieces *> &Table, int x, int y) override;
        int type() override;
        Pos getPos(table<Ichess_pieces *> &Table) const override;

        pawn(bool b);

        pawn *copy() override;
};


#endif