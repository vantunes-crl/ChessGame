#ifndef PAWN_HPP
#define PAWN_HPP

#include "Ichess_pieces.hpp"

class pawn : public Ichess_pieces
{

    public:
        void play() override;
        std::string type() override;
};




#endif