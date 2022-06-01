#ifndef PAWN_HPP
#define PAWN_HPP

#include "../Ichess_pieces.hpp"

class pawn : public Ichess_pieces
{

    public:
        void play(table<Ichess_pieces *> &Table) override;
        std::string type() override;

        pawn() {};

        // pawn(table<Ichess_pieces *> &Table) 
        // {
        //     Table[2][3] = new pawn;
        // };
};




#endif