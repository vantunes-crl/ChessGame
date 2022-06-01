#ifndef ROOK_HPP
#define ROOK_HPP

#include "../Ichess_pieces.hpp"

class rook : public Ichess_pieces
{
    public:
        void play(table<Ichess_pieces *> &Table) override;
        std::string type() override;

};

#endif