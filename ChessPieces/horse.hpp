#ifndef HORSE_HPP
#define HORSE_HPP

#include "../Ichess_pieces.hpp"

class horse : public Ichess_pieces
{
    public:
        void play(table<Ichess_pieces *> &Table, int x, int y) override;
        PIECES type() override;
        Pos getPos(table<Ichess_pieces *> &Table) const override;

        horse(bool b)
        {
            Color = b;
        }
    
};

#endif

