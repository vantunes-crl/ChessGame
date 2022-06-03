#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "../Ichess_pieces.hpp"

class knight : public Ichess_pieces 
{
    public:
        int play(table<Ichess_pieces *> &Table, int x, int y) override;
        int type() override;
        Pos getPos(table<Ichess_pieces *> &Table) const override;

        knight(bool b);
};



#endif