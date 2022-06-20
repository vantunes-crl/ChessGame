#ifndef QUEEN_HPP
#define QUEEN_HPP

#pragma once
#include "../Ichess_pieces.hpp"

class queen : public Ichess_pieces
{
    public:
        int play(table<Ichess_pieces *> &Table, int x, int y) override;
        int type() override;
        Pos getPos(table<Ichess_pieces *> &Table) const override;

        queen(bool b);
        queen *copy() override;
};

#endif