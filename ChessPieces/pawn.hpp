#ifndef PAWN_HPP
#define PAWN_HPP

#include "../Ichess_pieces.hpp"

class pawn : public Ichess_pieces
{
    public:
        void play(table<Ichess_pieces *> &Table) override;
        std::string type() override;

        Pos getPos(table<Ichess_pieces *> &Table) const override;
};




#endif