#ifndef ICHESS_PIECES_HPP
#define ICHESS_PIECES_HPP

#include <iostream>

class Ichess_pieces
{
    public:
        virtual void play() = 0;
        virtual std::string type() = 0;


    virtual ~Ichess_pieces() {};
};


#endif