#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "../Ichess_pieces.hpp"

class queen : public Ichess_pieces
{
    public:
        void play(table<Ichess_pieces *> &Table, int x, int y) override;
        PIECES type() override;
        Pos getPos(table<Ichess_pieces *> &Table) const override;

    queen(bool b)
    {
        Color = b;
    }
};

#endif