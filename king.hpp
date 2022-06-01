#ifndef KING_HPP
#define KING_HPP


#include "Ichess_pieces.hpp"

class king : public Ichess_pieces 
{
    public:
        void play() override;
        std::string type() override;

};



#endif