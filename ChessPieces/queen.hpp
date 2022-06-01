#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "../Ichess_pieces.hpp"

class queen : public Ichess_pieces
{
    public:
        void play(table<Ichess_pieces *> &Table) override;
        std::string type() override;

};

#endif