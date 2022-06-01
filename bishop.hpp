#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "Ichess_pieces.hpp"

class bishop : public Ichess_pieces
{
    public:
        void play() override;
        std::string type() override;
};




#endif