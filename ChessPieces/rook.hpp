#ifndef ROOK_HPP
#define ROOK_HPP
#pragma once
#include "../Ichess_pieces.hpp"

class rook : public Ichess_pieces
{
    public:
        int play(table<Ichess_pieces *> &Table, int x, int y) override;
        int type() override;
        Pos getPos(table<Ichess_pieces *> &Table) const override;

        rook(bool b);
        rook *copy() override;

};

#endif