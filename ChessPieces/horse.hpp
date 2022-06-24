#ifndef HORSE_HPP
#define HORSE_HPP
#pragma once
#include "../Ichess_pieces.hpp"

class horse : public Ichess_pieces
{
    public:
        int play(table<Ichess_pieces *> &Table, int x, int y) override;
        int type() override;
        Pos getPos(table<Ichess_pieces *> &Table) const override;
        bool getColor() const override;



        horse(bool b);
        horse *copy() override;
    private:
        bool Color;
};

#endif

