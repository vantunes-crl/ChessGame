#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "../Ichess_pieces.hpp"

class bishop : public Ichess_pieces
{
    public:
        void play(table<Ichess_pieces *> &Table) override;
        std::string type() override;
};




#endif