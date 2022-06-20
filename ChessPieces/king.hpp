#ifndef KING_HPP
#define KING_HPP
#pragma once
#include "../Ichess_pieces.hpp"

class king : public Ichess_pieces 
{
    public:
        int play(table<Ichess_pieces *> &Table, int x, int y) override;
        int type() override;
        Pos getPos(table<Ichess_pieces *> &Table) const override;

        king(bool b);
        king *copy() override;



};



#endif