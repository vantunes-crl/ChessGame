#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "Ichess_pieces.hpp"

class knight : public Ichess_pieces 
{
    public:
        void play() override;
        std::string type() override;

};



#endif