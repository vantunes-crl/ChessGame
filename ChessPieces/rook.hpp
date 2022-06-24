#ifndef ROOK_HPP
#define ROOK_HPP
#pragma once
#include "../Ichess_pieces.hpp"

class rook : public Ichess_pieces
{
    public:
        int play(Table_t &Table, Pos ToMovePos) override;
        int type() override;
        Pos getPos(Table_t &Table) const override;
        bool getColor() const override;
        rook(bool b);
        std::shared_ptr<Ichess_pieces> copy() override;
    private:
        bool Color;

};

#endif