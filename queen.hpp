#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "Ichess_pieces.hpp"

class queen : public Ichess_pieces
{
    public:
        void play() override;
        std::string type() override;

};

#endif