#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "../Ichess_pieces.hpp"

class bishop : public Ichess_pieces
{
    public:
        void play(table<Ichess_pieces *> &Table, int x, int y) override;
        PIECES type() override;
        Pos getPos(table<Ichess_pieces *> &Table) const override;

        bishop(bool b)
        {
            Color = b;
        }

};




#endif