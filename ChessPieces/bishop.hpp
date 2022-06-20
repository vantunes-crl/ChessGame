#ifndef BISHOP_HPP
#define BISHOP_HPP
#pragma once
#include "../Ichess_pieces.hpp"

class bishop : public Ichess_pieces
{
    public:
        int play(table<Ichess_pieces *> &Table, int x, int y) override;
        int type() override;
        Pos getPos(table<Ichess_pieces *> &Table) const override;
    
        bishop(bool b);
        bishop *copy() override;


};




#endif